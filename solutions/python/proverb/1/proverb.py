def proverb(*args, **kwargs):
    qualifier = kwargs.get("qualifier")
    qualifier = f" {qualifier}" if qualifier else ""
    result = []
    if not args:
        return result
    fst, *rest = args
    reason = fst
    while rest:
        snd, *rest = rest
        result += [f"For want of a {fst} the {snd} was lost."]
        fst = snd
    return result + [f"And all for the want of a{qualifier} {reason}."]