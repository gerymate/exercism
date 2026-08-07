package isbnverifier

type ISBN [10]byte

func IsValidISBN(isbn string) bool {
    isbn = remove_dashes(isbn)
    if len(isbn) != 10 {
    	return false
    }

    digits := parseISBNdigits(isbn)

    var digit_sum int
    for i, d := range(digits) {
        digit_sum += int(d) * (10-i)
    }
    return digit_sum % 11 == 0
}

func parseISBNdigits(isbn_str string) (isbn ISBN) {
	const ASCII_ZERO = 48
    for i, ch := range(isbn_str[:9]) {
        isbn[i] = byte(ch) - ASCII_ZERO
    } 
    if isbn_str[9] == 'X' {
        isbn[9] = 10
    } else {
        isbn[9] = byte(isbn_str[9]) - ASCII_ZERO
    }
    return
}

func remove_dashes(input string) (output string) {
    for _, ch := range(input) {
        if ch != '-' {
            output += string(ch)
        }
    }
    return
}
