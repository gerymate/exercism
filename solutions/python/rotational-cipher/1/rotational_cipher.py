def rotate(text: str, key):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    rot = alphabet[key:] + alphabet[:key]
    trans = str.maketrans(alphabet + alphabet.upper(), rot + rot.upper())
    return text.translate(trans)
