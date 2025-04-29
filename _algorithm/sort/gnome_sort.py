from const import NUMBERS_TO_SORT


def gnome_sort():
    numbers = NUMBERS_TO_SORT
    index = 0

    # インデックスがリストの長さより小さい間、以下の処理を繰り返す
    while index < len(numbers):
        # インデックスが0の場合、インデックスを1増やす
        if index == 0:
            index += 1
        # 現在の要素が前の要素より大きい場合、インデックスを1増やす
        if numbers[index] >= numbers[index - 1]:
            index += 1
        # 現在の要素が前の要素より小さい場合、要素を入れ替える
        else:
            numbers[index], numbers[index - 1] = numbers[index - 1], numbers[index]
            index -= 1

    return numbers


gnome_sorted_numbers = gnome_sort()

print(gnome_sorted_numbers)
