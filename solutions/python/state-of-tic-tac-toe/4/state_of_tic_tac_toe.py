def gamestate(board: [str]) -> str:
    num_of_xs = sum(1 for row in board for ch in row if ch == 'X')
    num_of_os = sum(1 for row in board for ch in row if ch == 'O')
    if num_of_xs > num_of_os + 1:
        raise ValueError('Wrong turn order: X went twice')
    if num_of_os > num_of_xs:
        raise ValueError('Wrong turn order: O started')

    winning_positions = (
        ((0,0), (0,1), (0,2)),
        ((1,0), (1,1), (1,2)),
        ((2,0), (2,1), (2,2)),
        ((0,0), (1,0), (2,0)),
        ((0,1), (1,1), (2,1)),
        ((0,2), (1,2), (2,2)),
        ((0,0), (1,1), (2,2)),
        ((0,2), (1,1), (2,0)),
    )
    xwins = 0
    owins = 0
    for ((y0, x0), (y1, x1), (y2, x2)) in winning_positions:
        if board[y0][x0] == board[y1][x1] == board[y2][x2] == 'O':
            owins += 1
        if board[y0][x0] == board[y1][x1] == board[y2][x2] == 'X':
            xwins += 1

    if xwins >= 1 and owins == 1:
        raise ValueError('Impossible board: game should have ended after the game was won')
    if xwins >= 1 or owins == 1:
        return 'win'
    if num_of_xs + num_of_os == 9:
        return 'draw'
    return 'ongoing'
