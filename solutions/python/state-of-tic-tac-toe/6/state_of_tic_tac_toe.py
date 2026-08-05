""" TicTacToe evaluator """

def gamestate(board: [str]) -> str:
    """ Return the state of the game based on the board """
    board: str = board[0] + board[1] + board[2]
    
    num_of_xs = sum(1 for char in board if char == 'X')
    num_of_os = sum(1 for char in board if char == 'O')
    if num_of_xs > num_of_os + 1:
        raise ValueError('Wrong turn order: X went twice')
    if num_of_os > num_of_xs:
        raise ValueError('Wrong turn order: O started')

    winning_positions = (
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6),
    )
    xwins = owins = 0
    for (pos0, pos1, pos2) in winning_positions:
        if board[pos0] == board[pos1] == board[pos2] == 'O':
            owins += 1
        if board[pos0] == board[pos1] == board[pos2] == 'X':
            xwins += 1

    if xwins >= 1 and owins == 1:
        raise ValueError('Impossible board: game should have ended after the game was won')
    if xwins >= 1 or owins == 1:
        return 'win'
    if num_of_xs + num_of_os == 9:
        return 'draw'
    return 'ongoing'
