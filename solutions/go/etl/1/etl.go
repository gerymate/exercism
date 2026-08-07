package etl

import "strings"

func Transform(in map[int][]string) map[string]int {
	out := make(map[string]int)
    for k, vs := range in {
        for _, v := range vs {
            out[strings.ToLower(v)] = k
        }
    }
    return out
}
