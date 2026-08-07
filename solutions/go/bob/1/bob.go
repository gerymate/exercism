// Package bob provides a conversation library
package bob

import "strings"

// Hey makes it possible to communicate with Bob
func Hey(remark string) string {
	remark = strings.TrimSpace(remark)
	switch {
	case 0 == len(remark):
		return "Fine. Be that way!"
	case isQuestion(remark) && isYell(remark):
		return "Calm down, I know what I'm doing!"
	case isQuestion(remark):
		return "Sure."
	case isYell(remark):
		return "Whoa, chill out!"
	default:
		return "Whatever."
	}
}

func isQuestion(text string) bool {
	return text[len(text)-1:] == "?"
}

func isYell(text string) bool {
	return text == strings.ToUpper(text) && strings.ToLower(text) != text
}