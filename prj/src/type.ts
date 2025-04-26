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

export type { ToolInfo, DiscoverResponse, InvokeRequest, InvokeResponse };
