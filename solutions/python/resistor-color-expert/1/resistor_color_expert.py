COLORS = [
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white"
]

METRICS = [
    "ohms",
    "kiloohms",
    "megaohms",
    "gigaohms"
]

TOLERANCE = {
    "grey": " ±0.05%",
    "violet": " ±0.1%",
    "blue": " ±0.25%",
    "green": " ±0.5%",
    "brown": " ±1%",
    "red": " ±2%",
    "gold": " ±5%",
    "silver": " ±10%"
}

def label(colors):
    value = COLORS.index(colors[0])
    value = 10 * value + COLORS.index(colors[1])
    if len(colors) == 5:
        value = 10 * value + COLORS.index(colors[2])
        zeros = COLORS.index(colors[3])
    else:
        zeros = COLORS.index(colors[2])

    while value >= 10:
        value /= 10
        zeros += 1

    value *= 10**(zeros % 3)
    value = round(value, 2)
    if value == float(int(value)):
        value = int(value)

    return f"{value} {METRICS[zeros // 3]}"


def resistor_label(colors):
    if len(colors) == 1:
        return "0 ohms"
    return f"{label(colors)}{TOLERANCE[colors[-1]]}"
