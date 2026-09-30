from enum import Enum

def spiral_matrix(size):
    result = [[0 for _ in range(size)] for _ in range(size)]
    Move = Enum('Move', 'RIGHT DOWN LEFT UP')
    action = Move.RIGHT
    x, y = 0, 0
    visited = lambda: result[y][x] > 0
    for i in range(size * size):
        result[y][x] = i + 1
        match action:
            case Move.RIGHT:
                x += 1
                if x == size or visited():
                    x -= 1
                    y += 1
                    action = Move.DOWN
            case Move.DOWN:
                y += 1
                if y == size or visited():
                    y -= 1
                    x -= 1
                    action = Move.LEFT
            case Move.LEFT:
                x -= 1
                if x < 0 or visited():
                    x += 1
                    y -= 1
                    action = Move.UP
            case Move.UP:
                y -= 1
                if y < 0 or visited():
                    y += 1
                    x += 1
                    action = Move.RIGHT

    return result

