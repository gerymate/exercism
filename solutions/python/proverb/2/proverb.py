def proverb(*things, qualifier=None):
    result = []
    if not things:
        return result
    qualifier = f" {qualifier}" if qualifier else ""
    fst, *rest = things
    reason = fst
    while rest:
        snd, *rest = rest
        result += [f"For want of a {fst} the {snd} was lost."]
        fst = snd
    return result + [f"And all for the want of a{qualifier} {reason}."]