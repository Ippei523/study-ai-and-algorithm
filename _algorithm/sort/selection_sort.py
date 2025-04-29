from const import NUMBERS_TO_SORT


def selection_sort():
    numbers = NUMBERS_TO_SORT
    print(f"numbers: {numbers}")

    for i in range(len(numbers)):
        # 最小値のインデックスをiとする
        min_index = i

        # i以降の要素で最小値を探す
        for j in range(i + 1, len(numbers)):
            print(f"numbers[i]: {numbers[i]}, numbers[j]: {numbers[j]}")
            if numbers[j] < numbers[min_index]:
                min_index = j
                print(f"min_index: {min_index}")

        print(f"numbers[i]: {numbers[i]}, numbers[min_index]: {numbers[min_index]}")
        numbers[i], numbers[min_index] = numbers[min_index], numbers[i]
        print(f"numbers: {numbers}")

    return numbers


selection_sorted_numbers = selection_sort()

print(selection_sorted_numbers)
