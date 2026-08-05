// Package acronym generates acronymes.
package acronym

import "strings"

// Abbreviate generates a capitalized abbrev. from a string.
func Abbreviate(s string) string {
	isSeparator := func(c rune) bool {
		return c == ' ' || c == '-'
	}
	words := strings.FieldsFunc(s, isSeparator)
	for i := range words {
		words[i] = string(words[i][0])
	}
	return strings.ToUpper(strings.Join(words, ""))
}