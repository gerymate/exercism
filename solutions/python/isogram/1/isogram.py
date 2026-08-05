def is_isogram(string):
    strong = [ch.lower() for ch in string if ch.isalpha()]
    letters = set(strong)
    return len(letters) == len(strong)
