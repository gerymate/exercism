def steps(number):
    if number < 1:
        raise ValueError("Only positive integers are allowed")
    
    step = 0
    while number > 1:
        step += 1
        is_even = number % 2 == 0
        number = number / 2 if is_even else 3 * number + 1

    return step
    
