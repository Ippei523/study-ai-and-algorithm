// src/index.ts
import express, { Request, Response } from "express";
import cors from "cors";

// --- 型定義 ---
interface ToolInfo {
  name: string;
  description: string;
}
interface DiscoverResponse {
  tools: ToolInfo[];
}
interface InvokeRequest {
  tool: string;
  args: Record<string, any>;
}
interface InvokeResponse {
  result: any;
}

// --- ツール一覧定義 ---
const tools: ToolInfo[] = [
  { name: "weather-fetch", description: "指定地点の天気を取得する" },
  // { name: 'db-query', description: 'データベースにクエリを投げる' },
  // …他ツールをここに追加…
];

// --- Express サーバー ---
const app = express();
app.use(cors());
app.use(express.json());

// /discover: 利用可能なツール一覧を返す
app.post("/discover", (_req: Request, res: Response<DiscoverResponse>) => {
  res.json({ tools });
});

// /invoke: 指定ツールを実行して結果を返す
app.post(
  "/invoke",
  async (req: Request<InvokeRequest>, res: Response<InvokeResponse>) => {
    const { tool, args } = req.body;

    try {
      let result: any;

      switch (tool) {
        case "weather-fetch":
          result = await fetchWeather(args.location);
          break;

        // case 'db-query':
        //   result = await runDbQuery(args.sql)
        //   break

        default:
          throw new Error(`Unknown tool: ${tool}`);
      }

      res.json({ result });
    } catch (err: any) {
      res.status(400).json({ result: { error: err.message } });
    }
  }
);

// --- ツール実装例 ---
async function fetchWeather(location: string): Promise<Record<string, any>> {
  // ここに外部API呼び出しなどの実装
  // 例：OpenWeatherMap を fetch して整形して返す
  return { location, temp: 22.5, condition: "Sunny" };
}

// --- サーバー起動 ---
const PORT = process.env.PORT || 8000;
app.listen(PORT, () => {
  console.log(`MCP server is running at http://localhost:${PORT}`);
});
