def classify(number):
    if number < 1:
        raise ValueError(f"{number} is not a natural number")

    divisors = [n for n in range(1, number // 2 + 1) if number % n == 0]
    aliquot_sum = sum(divisors)
    if aliquot_sum > number:
        return "abundant"
    elif aliquot_sum < number:
        return "deficient"
    else:
        return "perfect"
    