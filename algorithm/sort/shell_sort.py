from const import NUMBERS_TO_SORT


def shell_sort():
    numbers = NUMBERS_TO_SORT

    # 間隔を設定
    interval = len(numbers) // 2

    # 間隔が0になるまで以下の処理を繰り返す
    while interval > 0:
        for i in range(interval, len(numbers)):
            temp = numbers[i]
            j = i

            # jが間隔以上で、現在の要素が間隔前の要素より小さい場合、要素を入れ替える
            while j >= interval and numbers[j - interval] > temp:
                numbers[j] = numbers[j - interval]
                j -= interval
            numbers[j] = temp

        # 間隔を半分にする
        interval //= 2

    return numbers


sorted_numbers = shell_sort()

print(sorted_numbers)
