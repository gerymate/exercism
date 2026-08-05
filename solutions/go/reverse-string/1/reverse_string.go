// Package reverse reverses things
package reverse

import "strings"

// String returns the input string reversed
func String(input string) string {
	runes := strings.Split(input, "")
	reversed := ""
	for i := len(runes) - 1; i != -1; i-- {
		reversed += runes[i]
	}
	return reversed
}