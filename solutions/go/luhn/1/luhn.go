package luhn

func Valid(id string) bool {
	idStripped := removeWhiteSpace(id)
	if len(idStripped) <= 1 || hasNonDigit(idStripped) {
		return false
	}
	numbers := toIntSlice(idStripped)
	numbersPrepared := doubleEverySecondFromRight(numbers)
	return (Sum(numbersPrepared) % 10 == 0)
}

/// private functions 

func removeWhiteSpace(in string) (out string) {
	for _, ch := range in {
		if ch == ' ' || ch == '\t' || ch == '\n' {
			continue
			} else {
				out += string(ch)
			}
		}
		return
	}
	
	func hasNonDigit(str string) bool {
		for _, ch := range str {
			if !isDigit(ch) {
				return true
			}
		}
		return false
	}
	
	func isDigit(ch rune) bool {
		return '0' <= ch && ch <= '9'
	}

	func toIntSlice(strOfDigits string) []int {
		numbers := make([]int, len(strOfDigits))
		for i, ch := range strOfDigits {
			numbers[i] = toDigit(ch)
		}
		return numbers
	}

	func toDigit(ch rune) int {
		return int(ch) - '0'
	}
	
	func doubleEverySecondFromRight(numbers []int) []int {
		preparedNumbers := make([]int, len(numbers))
		lastIndex := len(numbers) - 1
		for i := 0; i <= lastIndex; i++ {
			x := numbers[lastIndex - i]
			x = (1 + (i % 2)) * x  // double every second
			if x > 9 {
				x -= 9
			}
			preparedNumbers[lastIndex - i] = x
		}
		return preparedNumbers
	}
	
	func Sum(numbersPrepared []int) int {
		sum := 0
		for _, v := range numbersPrepared {
			sum += v
		}
		return sum
	}
