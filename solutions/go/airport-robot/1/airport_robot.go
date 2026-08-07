package airportrobot

type Greeter interface {
	LanguageName() string
	Greet(name string) string
}

func SayHello(name string, gr Greeter) string {
	return "I can speak " + gr.LanguageName() + ": " + gr.Greet(name)
}

// Italian
type Italian struct{}

func (Italian) LanguageName() string {
	return "Italian"
}

func (Italian) Greet(name string) string {
	return "Ciao " + name + "!"
}

// Portuguese
type Portuguese struct{}

func (Portuguese) LanguageName() string {
	return "Portuguese"
}

func (Portuguese) Greet(name string) string {
	return "Olá " + name + "!"
}
