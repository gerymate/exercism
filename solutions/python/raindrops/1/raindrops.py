def convert(number):
    output = ''
    when_what = ((3, 'Pling'), (5, 'Plang'), (7, 'Plong'))
    for denominator, sound in when_what:
        if number % denominator == 0: output += sound
    if output == '': output = str(number)
    return output