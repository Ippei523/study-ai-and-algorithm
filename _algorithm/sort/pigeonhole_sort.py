def pigeonhole_sort():
    arr = [8, 3, 2, 7, 4, 6, 8]

    # 大きい値と小さい値を取得
    min_val = min(arr)
    max_val = max(arr)

    # Pigeonholeのリストを作成
    holes = [0] * (max_val - min_val + 1)

    # Pigeonholeに値を入れる
    for x in arr:
        holes[x - min_val] += 1

    i = 0
    for count in range(len(holes)):
        # holes[count]が0になるまで、最小の値と現在の配列にある要素の値をarr[i]に入れる
        while holes[count] > 0:
            holes[count] -= 1
            arr[i] = count + min_val
            i += 1

    return arr


print(pigeonhole_sort())  # [2, 3, 4, 6, 7, 8, 8]を出力
