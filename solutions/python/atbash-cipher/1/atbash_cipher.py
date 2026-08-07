CYPHER = {chr(ord('a')+nth): chr(ord('z')-nth) for nth in range(ord('z')-ord('a')+1)}

def encode(plain_text):
    prepared = plain_text.replace(' ', '').replace('.', '').replace(',', '').lower()
    result = ''
    for index, ch in enumerate(list(prepared)):
        altered = CYPHER.get(ch, ch)
        result += altered
        if index % 5 == 4:
            result += ' '
    return result.rstrip()

def decode(ciphered_text):
    return ''.join([CYPHER.get(ch, ch) for ch in ciphered_text if ch != ' '])
