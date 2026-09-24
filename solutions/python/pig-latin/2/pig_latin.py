import re

def translate(text):
    def pigize(word):
        if re.match(r'[aeiou]|xr|yt', word):
            return word + 'ay'
        m = (re.match(r'([^aeiou]*qu)(.*)', word) or
            re.match(r'([^aeiou]+)(y.*)', word) or
            re.match(r'([^aeiou]+)(.*)', word))
        return m.group(2) + m.group(1) + 'ay'
    return ' '.join(map(pigize, text.split()))