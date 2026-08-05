package thefarm

import (
	"errors"
	"fmt"
)

// See types.go for the types defined for this exercise.

// TODO: Define the SillyNephewError type here.
type SillyNephewError struct {
	numberOfCows int
}

func NewSillyNephewError(cows int) SillyNephewError {
	return SillyNephewError{numberOfCows: cows}
}

func (sn SillyNephewError) Error() string {
	return fmt.Sprintf("silly nephew, there cannot be %d cows", sn.numberOfCows)
}

// DivideFood computes the fodder amount per cow for the given cows.
func DivideFood(weightFodder WeightFodder, cows int) (float64, error) {
	if cows == 0 {
		return 0, errors.New("division by zero")
	}

	amount, err := weightFodder.FodderAmount()

	if err == ErrScaleMalfunction {
		amount *= 2
	} else if err != nil {
		return 0, err
	}

	if amount < 0 {
		return 0, errors.New("negative fodder")
	}

	if cows < 0 {
		return 0, NewSillyNephewError(cows)
	}

	return amount / float64(cows), nil
}
