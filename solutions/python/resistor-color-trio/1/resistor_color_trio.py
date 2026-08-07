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

def label(colors):
    value1 = COLORS.index(colors[0])
    value2 = COLORS.index(colors[1])
    zeros = COLORS.index(colors[2])
    if value2 == 0:
        value = value1
        zeros += 1
    else:
        value = 10 * value1 + value2
    return f"{value * 10**(zeros%3) } {METRICS[zeros // 3]}"
