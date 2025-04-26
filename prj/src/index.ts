// src/index.ts
import express, { Request, Response } from "express";
import cors from "cors";
import {
  DiscoverResponse,
  InvokeRequest,
  InvokeResponse,
  ToolInfo,
} from "./type";
import { fetchWeather } from "./tools/weather";
import { fetchSoccerNewsWithAnalysis } from "./tools/soccerNews";

// --- ツール一覧定義 ---
const tools: ToolInfo[] = [
  { name: "weather-fetch", description: "指定地点の天気を取得する" },
  { name: "soccer-news", description: "最新のサッカーニュースを取得する" },
  // { name: 'db-query', description: 'データベースにクエリを投げる' },
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

        case "soccer-news":
          result = await fetchSoccerNewsWithAnalysis(args);
          break;

        default:
          throw new Error(`Unknown tool: ${tool}`);
      }

      res.json({ result });
    } catch (err: any) {
      res.status(400).json({ result: { error: err.message } });
    }
  }
);

// --- サーバー起動 ---
const PORT = process.env.PORT || 8000;
app.listen(PORT, () => {
  console.log(`MCP server is running at http://localhost:${PORT}`);
});
