def is_armstrong_number(number):
    digits = str(number)
    power = len(digits)
    powered_digits = [int(ch) ** power for ch in digits]
    return sum(powered_digits) == number
