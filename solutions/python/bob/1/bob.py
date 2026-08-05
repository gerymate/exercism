def response(hey_bob):
    is_question = hey_bob.rstrip().endswith('?')
    is_yell = hey_bob == hey_bob.upper() != hey_bob.lower()
    is_silence = hey_bob.isspace() or not hey_bob
    if is_question and is_yell:
        result = 'Calm down, I know what I\'m doing!'
    elif is_question:
        result = 'Sure.'
    elif is_yell:
        result = 'Whoa, chill out!'
    elif is_silence:
        result = 'Fine. Be that way!'
    else:
        result = 'Whatever.'
    return result
    