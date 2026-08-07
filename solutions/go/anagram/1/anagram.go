package anagram

import (
	"strings"
    "slices"
    )

func Detect(subject string, candidates []string) []string {
	var output []string
    subject_l := strings.ToLower(subject)
    sub_chars := strings.Split(subject_l, "")
    slices.Sort(sub_chars)
    
	for _, candidate := range(candidates) {
        candidate_l := strings.ToLower(candidate)
        candidate_chars := strings.Split(candidate_l, "")
        slices.Sort(candidate_chars)
        is_anagram := slices.Equal(sub_chars, candidate_chars)
        if is_anagram && candidate_l != subject_l {
            output = append(output, candidate)
        }
    }
    return output
}
