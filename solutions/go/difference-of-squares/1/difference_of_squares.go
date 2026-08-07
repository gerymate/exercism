// Package diffsquares provides some calculation on natural numbers
package diffsquares

// SquareOfSums calculates the square of the sum of the first n natural numbers
func SquareOfSums(n int) int {
	sums := 0
	for i := 1; i <= n; i++ {
		sums += i
	}
	return sums * sums
}

// SumOfSquares calculates the sum of the squares of the first n natural numbers
func SumOfSquares(n int) int {
	sum := 0
	for i := 1; i <= n; i++ {
		sum += i * i
	}
	return sum
}

// Difference between square of sums and sum of squares of the first n NATs
func Difference(n int) int {
	return SquareOfSums(n) - SumOfSquares(n)
}