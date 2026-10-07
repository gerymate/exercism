""" A forth evaluator """

class StackUnderflowError(Exception):
    """Exception raised when Stack is not full.
        message: explanation of the error
    """
    def __init__(self, message) -> None:
        self.message = message

def evaluate(input_data: list[str]):
    """ Evaluate forth expressions """
    stack: list[int] = []
    definitions: dict[str, str] = {}
    for a_line in input_data:
        line = a_line.upper()
        if line[0] == ":" and line[-1] == ";":
            new_word, _, definition = line[2:-2].partition(" ")
            new_word_is_negative_number = ( new_word[0] == "-"
                                           and len(new_word) > 1
                                           and new_word[1:].isdecimal() )
            if new_word.isdecimal() or new_word_is_negative_number:
                raise ValueError("illegal operation")
            definition = substitude_definitions(definition, definitions)
            definitions[new_word] = definition
        else:
            line = substitude_definitions(line, definitions)
            process_tokens(line, stack)
        print(definitions)
    return stack

def substitude_definitions(text: str, definitions: dict[str, str]) -> str:
    """ Substitute all custom defined words in the line first """
    for key in definitions:
        text = text.replace(key, definitions[key])
    return text

def process_tokens(line: str, stack: list[int]) -> list[int]:
    """ Process keyword tokens """
    tokens = iter(line.split())
    while token := next(tokens, None):
        try:
            if token in "+-*/":
                value1 = stack.pop()
                value2 = stack.pop()
                if token == "/":
                    token = "//"
                stack.append(int(eval(str(value2) + token + str(value1))))
            elif token == "DUP":
                stack.append(stack[-1])
            elif token == "DROP":
                stack.pop()
            elif token == "SWAP":
                stack[-2], stack[-1] = stack[-1], stack[-2]
            elif token == "OVER":
                stack.append(stack[-2])
            elif token[0].isdigit() or token[0] == "-":
                stack.append(int(token))
            else:
                raise ValueError("undefined operation")

        except IndexError as err:
            raise StackUnderflowError("Insufficient number of items in stack") from err
        except ZeroDivisionError as err:
            raise ZeroDivisionError("divide by zero") from err
    return stack
