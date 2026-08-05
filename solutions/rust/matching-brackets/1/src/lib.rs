pub fn brackets_are_balanced(string: &str) -> bool {
    let mut stack: Vec<char> = Vec::new();
    for ch in string.chars() {
        match &ch {
            '(' => stack.push(')'), 
            '[' => stack.push(']'), 
            '{' => stack.push('}'),
            ')' | ']' | '}' => {
                match stack.pop() {
                    Some(closing) => if closing != ch { return false },
                    None => return false,
                }
            },
            _ => ()
        }
    }
    stack.is_empty()
}
