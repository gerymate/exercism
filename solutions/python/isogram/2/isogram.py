""" Module for finding out if a string is an isogram """

def is_isogram(string):
    strong = [char.lower() for char in string if char.isalpha()]
    letters = set(strong)
    return len(letters) == len(strong)
