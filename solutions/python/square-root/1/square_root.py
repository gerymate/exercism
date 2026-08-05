def square_root(number):
    bottom, top = 0, number
    n = number // 2
    while (square := (n * n)) != number:
        if square < number:
            bottom = n + 1
        else:
            top = n - 1
        n = (bottom + top) // 2
    return n
