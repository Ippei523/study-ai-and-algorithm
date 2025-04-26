// --- ツール実装例 ---
export async function fetchWeather(
  location: string
): Promise<Record<string, any>> {
  // ここに外部API呼び出しなどの実装
  // 例：OpenWeatherMap を fetch して整形して返す
  return { location, temp: 22.5, condition: "Sunny" };
}
