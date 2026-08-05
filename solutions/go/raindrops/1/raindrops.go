// Package raindrops contains some toys with primes
package raindrops

import "fmt"

// Convert takes a number and converts it into raindrop sounds
func Convert(num int) string {
	rain := pling(num) + plang(num) + plong(num)
	if rain != "" {
		return rain
	}
	return fmt.Sprint(num)

}

func pling(num int) string {
	if num%3 == 0 {
		return "Pling"
	}
	return ""
}

func plang(num int) string {
	if num%5 == 0 {
		return "Plang"
	}
	return ""
}

func plong(num int) string {
	if num%7 == 0 {
		return "Plong"
	}
	return ""
}