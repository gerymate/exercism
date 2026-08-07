def is_armstrong_number(number):
    number_as_string = str(number)
    digits = list(number_as_string)
    power = len(digits)
    powered_digits = [int(ch) ** power for ch in digits]
    return sum(powered_digits) == number
