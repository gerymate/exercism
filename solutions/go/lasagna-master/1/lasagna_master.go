package lasagna

// TODO: define the 'PreparationTime()' function
func PreparationTime(layers []string, averagePrepTime int) int {
	if averagePrepTime == 0 {
		averagePrepTime = 2
	}
	return len(layers) * averagePrepTime
}

// TODO: define the 'Quantities()' function
func Quantities(layers []string) (noodles int, sauce float64) {
	for i := 0; i != len(layers); i++ {
		switch layers[i] {
		case "noodles":
			noodles += 50
		case "sauce":
			sauce += 0.2
		}
	}
	return
}

// TODO: define the 'AddSecretIngredient()' function
func AddSecretIngredient(friendsIngredients, ownIngredients []string) {
	ownIngredients[len(ownIngredients)-1] = friendsIngredients[len(friendsIngredients)-1]
}

// TODO: define the 'ScaleRecipe()' function
func ScaleRecipe(amounts []float64, portions int) []float64 {
	var scaledAmounts []float64
	scale := float64(portions) / 2
	for i := 0; i != len(amounts); i++ {
		scaledAmounts = append(scaledAmounts, scale*amounts[i])
	}
	return scaledAmounts
}
