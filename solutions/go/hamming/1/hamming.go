// Package hamming calculates the hamming distance between two DNA sequences.
package hamming

import "errors"

// Distance calculates hamming distance between same length DNA sequences.
func Distance(a, b string) (int, error) {
	if len(a) != len(b) {
		return -1, errors.New("The 2 DNA are not the same length!")
	}

	hamm := 0
	for i := range a {
		if a[i] != b[i] {
			hamm++
		}
	}
	return hamm, nil
}