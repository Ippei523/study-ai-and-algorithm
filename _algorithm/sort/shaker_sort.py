from const import NUMBERS_TO_SORT


def shaker_sort():
    numbers = NUMBERS_TO_SORT
    start = 0
    end = len(numbers) - 1

    while True:
        last_swapped_index = 0

        # 末尾まで移動
        for i in range(start, end):
            # 現在の要素が次の要素より大きい場合、要素を入れ替える
            if numbers[i] > numbers[i + 1]:
                numbers[i], numbers[i + 1] = numbers[i + 1], numbers[i]
                last_swapped_index = i

        end = last_swapped_index

        # 末尾まで移動しても要素が入れ替わらなかった場合、ソート完了
        if start >= end:
            break

        # 先頭まで移動
        for i in range(end, start, -1):
            # 現在の要素が前の要素より小さい場合、要素を入れ替える
            if numbers[i] < numbers[i - 1]:
                numbers[i], numbers[i - 1] = numbers[i - 1], numbers[i]
                last_swapped_index = i

        start = last_swapped_index

        # 先頭まで移動しても要素が入れ替わらなかった場合、ソート完了
        if start >= end:
            break

    return numbers


arranged_number = shaker_sort()
print(arranged_number)
