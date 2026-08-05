def rows(letter):
    ord_a = ord('A')
    length = ord(letter) - ord_a + 1
    result = []
    for value in range(length):
        outer_space = length - value - 1
        inner_space = value * 2 - 1
        if inner_space > 0:
            line = f"{' ' * outer_space}{chr(ord_a + value)}{' ' * inner_space}{chr(ord_a + value)}{' ' * outer_space}"
        else:
            line = f"{' ' * outer_space}A{' ' * outer_space}"
        result.append(line)
        
    result.extend(result[-2::-1])
    
    return result
