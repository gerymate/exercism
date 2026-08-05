def transform(legacy_data):
    new_format = {}
    for point, letters in legacy_data.items():
        for letter in letters:
            new_format[letter.lower()] = point
    return new_format