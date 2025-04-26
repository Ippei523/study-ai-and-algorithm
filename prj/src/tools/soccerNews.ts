import Parser from "rss-parser";
import { OpenAI } from "openai";
import pLimit from "p-limit";
import * as dotenv from "dotenv";

dotenv.config();

const parser = new Parser({
  requestOptions: {
    headers: {
      "User-Agent": "Mozilla/5.0 (compatible; MySoccerBot/1.0)",
    },
  },
});

const openai = new OpenAI({
  apiKey: process.env.OPENAI_API_KEY!,
});

const rssFeeds = [
  "https://www.soccer-king.jp/feed",
  "https://www.goal.com/feeds/en/news?fmt=rss",
  "https://sports.yahoo.com/soccer/rss",
  "https://feeds.bbci.co.uk/sport/football/rss.xml",
  "https://www.espn.com/espn/rss/soccer/news",
  "https://www.theguardian.com/football/rss",
  "https://www.jleague.jp/rss/news.xml",
  "https://www.footballchannel.jp/feed",
  "https://number.bunshun.jp/list/rss/soccer",
];

// ニュース要約＋関連度分析
async function analyzeNews(
  title: string,
  keyword: string
): Promise<{ summary: string; score: number }> {
  const messages = [
    {
      role: "system" as const,
      content:
        "あなたはサッカー記者です。以下のニュースタイトルに対して、要約（100文字以内）と、指定されたキーワードとの関連度スコア（0.0〜1.0）を返してください。",
    },
    {
      role: "user" as const,
      content: `タイトル: ${title}\nキーワード: ${keyword}`,
    },
  ];

  const controller = new AbortController();
  const timeout = setTimeout(() => controller.abort(), 20000); // 20秒でタイムアウト

  try {
    const res = await openai.chat.completions.create({
      model: "gpt-4o", // 必要に応じて "gpt-3.5-turbo" に切り替え
      messages,
      temperature: 0.4,
    });

    clearTimeout(timeout);

    const content = res.choices[0].message.content ?? "";
    const summaryMatch = content.match(/要約[:：](.+)/);
    const scoreMatch = content.match(/スコア[:：]\s?([0-1]\.\d+)/);

    console.log("✅ GPT出力:", content);

    return {
      summary: summaryMatch?.[1]?.trim() ?? "",
      score: parseFloat(scoreMatch?.[1] ?? "0"),
    };
  } catch (err) {
    clearTimeout(timeout);
    console.error("❌ analyzeNews API失敗:", err);
    return { summary: "", score: 0 };
  }
}

// メイン関数：RSS + GPT要約 + スコア付け
export async function fetchSoccerNewsWithAnalysis(args: { keyword: string }) {
  const keyword = args.keyword;
  const allItems: { title: string; link: string; pubDate: string }[] = [];

  for (const url of rssFeeds) {
    try {
      const feed = await parser.parseURL(url);
      const items = feed.items.slice(0, 10).map((item) => ({
        title: item.title ?? "",
        link: item.link ?? "",
        pubDate: item.pubDate ?? "",
      }));
      allItems.push(...items);
    } catch (e) {
      console.warn(`⚠️ RSS取得失敗: ${url}`, e);
    }
  }

  const limit = pLimit(5);

  const analyzed = await Promise.all(
    allItems.slice(0, 3).map((item) =>
      limit(async () => {
        try {
          const result = await analyzeNews(item.title, keyword);
          return { ...item, ...result };
        } catch (err) {
          console.error("❌ 分析失敗:", item.title, err);
          return { ...item, summary: "", score: 0 };
        }
      })
    )
  );

  return analyzed
    .filter((item) => item.summary && item.score > 0)
    .sort((a, b) => b.score - a.score)
    .slice(0, 10);
}
