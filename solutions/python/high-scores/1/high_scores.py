def latest(scores : [int]):
    return scores[-1]


def personal_best(scores : [int]):
    return max(scores)


def personal_top_three(scores : [int]):
    return sorted(scores, reverse=True)[:3]
