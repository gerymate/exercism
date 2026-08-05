package sorting

import (
	"fmt"
	"strconv"
)

// DescribeNumber should return a string describing the number.
func DescribeNumber(f float64) string {
	return fmt.Sprintf("This is the number %.1f", f)
}

type NumberBox interface {
	Number() int
}

// DescribeNumberBox should return a string describing the NumberBox.
func DescribeNumberBox(nb NumberBox) string {
	return fmt.Sprintf("This is a box containing the number %v.0", nb.Number())
}

type FancyNumber struct {
	n string
}

func (i FancyNumber) Value() string {
	return i.n
}

type FancyNumberBox interface {
	Value() string
}

// ExtractFancyNumber should return the integer value for a FancyNumber
// and 0 if any other FancyNumberBox is supplied.
func ExtractFancyNumber(fnb FancyNumberBox) int {
	fancyNumber, ok := fnb.(FancyNumber)
	if !ok {
		return 0
	}

	number, err := strconv.Atoi(fancyNumber.Value())
	if err != nil {
		return 0
	}

	return number
}

// DescribeFancyNumberBox should return a string describing the FancyNumberBox.
func DescribeFancyNumberBox(fnb FancyNumberBox) string {
	return fmt.Sprintf("This is a fancy box containing the number %v.0", ExtractFancyNumber(fnb))
}

// DescribeAnything should return a string describing whatever it contains.
func DescribeAnything(i interface{}) string {
	/*
	   - `int` and `float64` should both delegate to `DescribeNumber`
	   - `NumberBox` should delegate to `DescribeNumberBox`
	   - `FancyNumberBox` should delegate to `DescribeFancyNumberBox`
	   - anything else should result in `"Return to sender"`
	*/
	switch num := i.(type) {
	case int:
		return DescribeNumber(float64(num))
	case float64:
		return DescribeNumber(num)
	case NumberBox:
		return DescribeNumberBox(num)
	case FancyNumberBox:
		return DescribeFancyNumberBox(num)
	default:
		return "Return to sender"
	}
}
