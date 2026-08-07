// Package leap provides utility functions that tell wether a year is leap year or not
package leap

// IsLeapYear returns true if the input is a leap year, false otherwise
func IsLeapYear(year int) bool {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0
}
