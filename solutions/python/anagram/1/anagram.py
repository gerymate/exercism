def find_anagrams(word, candidates):
    low_word = word.lower()
    sorted_word = sorted(low_word)
    return [
        candidate 
        for candidate in candidates 
        if sorted(low_cand := candidate.lower()) == sorted_word 
        and low_cand != low_word]
