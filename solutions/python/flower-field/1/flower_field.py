def annotate(garden):
    if not garden:
        return []
    height = len(garden)
    width = len(garden[0])
    offsets = [(y, x) for x in (-1, 0, 1) for y in (-1, 0, 1)]
    offsets.remove((0,0))
    result = []
    invalid_coord = lambda x, y: x < 0 or x >= width or y < 0 or y >= height
    is_flower = lambda x, y: garden[y][x] == '*'
    
    for y, line in enumerate(garden):
        if len(line) != width:
            raise ValueError("The board is invalid with current input.")
        new_line = []
        for x, ch in enumerate(line):
            if ch == '*':
                new_line.append(ch)
            elif ch == ' ':
                number = 0
                for (dy, dx) in offsets:
                    check_y, check_x = y + dy, x + dx
                    if invalid_coord(check_x, check_y):
                        continue
                    if is_flower(check_x, check_y):
                        number += 1
                new_line.append(' ' if number == 0 else str(number))
            else:
                raise ValueError("The board is invalid with current input.")
        result.append(''.join(new_line))
    return result

        