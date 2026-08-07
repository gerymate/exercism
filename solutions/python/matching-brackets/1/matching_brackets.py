def is_paired(input_string):
    needs = []
    
    for ch in input_string:
        if ch == '[':
            needs.append(']')
        if ch == '{':
            needs.append('}')
        if ch == '(':
            needs.append(')')
        try:
            if ch in ['}', ']', ')']:
                if ch != needs.pop():
                    raise ValueError("unbalanced")
        except:
            return False
        
    return not bool(needs)
