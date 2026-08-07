package wordcount

import (
    "unicode"
    "strings"
)

type Frequency map[string]int

func WordCount(phrase string) Frequency {
    wc := make(Frequency)
    var word string
    count_word := func() {
        word = strings.Trim(word, "'")
        if len(word) != 0 {
    		wc[strings.ToLower(word)] += 1
            word = ""
        }
    }
    for _, ch := range phrase {
        if unicode.IsLetter(ch) || unicode.IsDigit(ch) || ch == '\'' {
            word += string(ch)
            continue
        }
		count_word()
    }
    count_word()
	return wc
}
