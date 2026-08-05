def encode(numbers):
    result = []
    for number in numbers:
        encoded = []
        if number == 0:
            result.append(0)
            continue
        last = True
        while number:
            code = number & 0b00000000_00000000_00000000_0111_1111
            if not last:
                code |= 0b1000_0000
            last = False
            number >>= 7
            encoded.insert(0, code)
        result.extend(encoded)
    return result

def decode(bytes_):
    result = []
    n = 0
    final = False
    for byte in bytes_:
        final = 0 == (byte & 0b1000_0000)
        n |= (byte & 0b0111_1111)
        if final:
            result.append(n)
            n = 0
        else:
            n <<= 7
    if not final:
        raise ValueError("incomplete sequence")
    return result