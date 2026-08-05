// Package isogram helps helps to determine certain properties of words
package isogram

import "strings"

// IsIsogram determines if a given word is a nonpattern word
func IsIsogram(word string) bool {
	letters := map[rune]bool{}
	for _, ch := range strings.ToLower(word) {
		if ch == ' ' || ch == '-' {
			continue
		}
		_, was := letters[ch]
		if was {
			return false
		} else {
			letters[ch] = true
		}
	}
	return true
}