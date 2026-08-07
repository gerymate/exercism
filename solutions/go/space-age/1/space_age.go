// Package space calculates measures on other planets.
package space

type Planet string

// Age converts ages given in seconds into years of different planets.
func Age(secs float64, planet Planet) float64 {
	earth := secs / 31557600
	switch planet {
	case "Earth":
		return earth
	case "Mercury":
		return earth / 0.2408467
	case "Venus":
		return earth / 0.61519726
	case "Mars":
		return earth / 1.8808158
	case "Jupiter":
		return earth / 11.862615
	case "Saturn":
		return earth / 29.447498
	case "Uranus":
		return earth / 84.016846
	case "Neptune":
		return earth / 164.79132
	}
	return 0
}