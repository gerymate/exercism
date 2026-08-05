def recite(start_verse, end_verse):
    nths = ('first', 'second', 'third', 'fourth', 'fifth', 'sixth', 'seventh', 'eighth', 'ninth', 'tenth', 'eleventh', 'twelfth')
    lines = (
        "On the ",
        " day of Christmas my true love gave to me: ",
        "twelve Drummers Drumming, ",
        "eleven Pipers Piping, ",
        "ten Lords-a-Leaping, ",
        "nine Ladies Dancing, ",
        "eight Maids-a-Milking, ",
        "seven Swans-a-Swimming, ",
        "six Geese-a-Laying, ",
        "five Gold Rings, ",
        "four Calling Birds, ",
        "three French Hens, ",
        "two Turtle Doves, and ",
        "a Partridge in a Pear Tree."
        )
    result = []

    for verse_number in range(start_verse - 1, end_verse):
        verse = lines[0] + nths[verse_number] + lines[1]
        for number in range(verse_number + 1):
            verse += lines[13 - verse_number + number]    
        result.append(verse)
    return result