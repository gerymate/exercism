def is_pangram(sentence : str):
    letters = [ch for ch in sentence.lower() if ch.isalpha()]
    return len(set(letters)) == 26  # a pangram is by definition 26 letters long
