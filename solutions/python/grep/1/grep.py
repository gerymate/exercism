import re
from dataclasses import dataclass

@dataclass
class Options:
    line_numbers: bool = False
    filenames_only: bool = False
    ignore_case: bool = False
    invert: bool = False
    whole_line: bool = False
    filenames: bool = False
    
    def __init__(self, flags):
        if 'n' in flags:
            self.line_numbers = True
        if 'l' in flags:
            self.filenames_only = True
        if 'i' in flags:
            self.ignore_case = True
        if 'v' in flags:
            self.invert = True
        if 'x' in flags:
            self.whole_line = True

def grep_file(regexp, options, filename):
    output = ''
    with open(filename) as file:
        for line_no, line in enumerate(file, 1):
            found = regexp.search(line)
            if options.invert:
                found = not found
            if found:
                if options.filenames_only:
                    output += filename + '\n'
                    break
                if options.filenames:
                    output += filename + ':'
                if options.line_numbers:
                    output += str(line_no) + ':'
                output += line
    return output
    

def grep(pattern, flags, files):
    output = ''
    options = Options(flags)
    if len(files) > 1:
        options.filenames = True

    if options.whole_line:
        pattern = '^' + pattern + '$'

    re_flags = re.IGNORECASE if options.ignore_case else 0
    my_regexp = re.compile(pattern, re_flags)

    for name in files:
        output += grep_file(my_regexp, options, name)

    return output
