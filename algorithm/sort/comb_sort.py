from const import NUMBERS_TO_SORT


def comb_sort():
    numbers = NUMBERS_TO_SORT

    interval = len(numbers) * 10 // 13

    while True:
        swaps = 0

        for i in range(len(numbers) - interval):
            if numbers[i] > numbers[i + interval]:
                numbers[i], numbers[i + interval] = numbers[i + interval], numbers[i]
                swaps += 1

        if interval == 1 and swaps == 0:
            break
        else:
            interval = max(1, interval * 10 // 13)

    return numbers


numbers = comb_sort()
print(numbers)
