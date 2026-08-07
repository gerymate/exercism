from collections import Counter

def count_words(sentence):
    words = []
    word = []
    is_word = False
    for ch in sentence:
        if ch.isalpha() or ch.isdigit():
            is_word = True
            word.append(ch.lower())
        elif is_word and ch == "'":
            word.append(ch)
        elif word:
            words.append(''.join(word).rstrip("'"))
            word.clear()
            is_word = False
    if word:
        words.append(''.join(word).rstrip("'"))

    stats = Counter(words)
    return dict(stats)
