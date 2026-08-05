from math import sqrt

def classify(number):
    if number < 1:
        raise ValueError(f"{number} is not a natural number")
    if number == 1:
        return "deficient"

    limit = int(sqrt(number)) + 1
    divisors = {1}
    divisors = {(n, number // n) for n in range(2, limit) if number % n == 0

    aliquot_sum = sum(divisors)
    if aliquot_sum > number:
        return "abundant"
    elif aliquot_sum < number:
        return "deficient"
    else:
        return "perfect"
    