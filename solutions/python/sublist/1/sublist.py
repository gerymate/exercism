"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = -1
SUPERLIST = 1
EQUAL = 0
UNEQUAL = None


def sublist(list_one, list_two):
    def is_sublist(a, b, begin):
        if not a:
            return True
        length = len(a)
        while begin + length < len(b):
            try:
                begin = b.index(a[0], begin)
            except ValueError:
                return False
            if b[begin:begin+length] == a:
                return True
            begin += 1
        return False
    if list_one == list_two:
        return EQUAL
    if is_sublist(list_one, list_two, 0):
        return SUBLIST
    if is_sublist(list_two, list_one, 0):
        return SUPERLIST
    return UNEQUAL

