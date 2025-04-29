from const import NUMBERS_TO_SORT


def bubble_sort():
    numbers = NUMBERS_TO_SORT

    # iは使用しないので、_に変更
    for _ in range(len(numbers)):
        for j in range(len(numbers) - 1):
            # 現在の要素が次の要素より大きい場合、要素を入れ替える
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = (
                    numbers[j + 1],
                    numbers[j],
                )
    return numbers


arranged_number = bubble_sort()
print(arranged_number)
