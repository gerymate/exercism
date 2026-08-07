// Package twofer is a simple naming game.
package twofer

// ShareWith shares something with the person given as an argument
func ShareWith(name string) string {
	if name == "" {
		name = "you"
	}
	return "One for " + name + ", one for me."
}