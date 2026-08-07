def commands(binary_str):
    actions = ["wink", "double blink", "close your eyes", "jump"]
    result = []
    digits = list(reversed(binary_str))
    reverse = digits.pop() == '1'
    for index, digit in enumerate(digits):
        if digit == '1':
            result.append(actions[index])
    if reverse: 
        result.reverse()
    return result