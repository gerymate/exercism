// Package weather provides a basic weather service API.
package weather

// CurrentCondition describes weather condition at any time.
var CurrentCondition string
// CurrentLocation contains the GPS coordinates the forecast relies to.
var CurrentLocation string

// Forecast takes a city name and a weather condition as a tring, and returns a weather report.
func Forecast(city, condition string) string {
	CurrentLocation, CurrentCondition = city, condition
	return CurrentLocation + " - current weather condition: " + CurrentCondition
}
