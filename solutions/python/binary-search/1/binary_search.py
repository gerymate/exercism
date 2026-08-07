def find(search_list, value):
    first = 0
    last = len(search_list) - 1
    
    while first <= last:
        middle = (first + last) // 2
        middle_item = search_list[middle]
        if middle_item == value:
            return middle
        if middle_item < value:
            first = middle + 1
        else:
            last = middle - 1
    raise ValueError("value not in array")
