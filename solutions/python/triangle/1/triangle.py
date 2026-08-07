def equilateral(sides):
    return is_triangle(sides) and sides[0] == sides[1] == sides[2]


def isosceles(sides):
    return is_triangle(sides) and (sides[0] == sides[1] or sides[1] == sides[2] or sides[2] == sides[0])


def scalene(sides):
    return is_triangle(sides) and sides[0] != sides[1] != sides[2] != sides[0]


def is_triangle(sides):
    a, b, c = sides
    return False if a + b < c or a + c < b or b + c < a or 0 == a == b == c else True 