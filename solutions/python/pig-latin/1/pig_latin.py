def translate(text):
    vowels = ['a', 'e', 'i', 'o', 'u']
    result = []
    for word in text.split():
        starts_vowel = word[0] in vowels
        # rule 1
        if starts_vowel or len(word) > 1 and word[:2] in ['xr', 'yt', 'ay']:
            result.append(word + 'ay')
            break
        # rule 2 & 4
        fp = 0
        while len(word) > fp and (ch := word[fp]) not in vowels:
            if fp > 0 and ch == 'y':
                break
            fp += 1
        # rule 3
        if word[fp-1] == 'q' and len(word) > fp and word[fp] == 'u':
            fp += 1
        result.append(word[fp:] + word[:fp] + 'ay')
    return ' '.join(result)
    
