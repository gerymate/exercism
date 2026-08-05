pub fn reverse(input: &str) -> String {
    // create output variable
    let n = input.len();
    let mut output = String::with_capacity(n);

    // reverse input into output
    for i in 1..=n {
        let mut chars = input.chars();
        match chars.nth(n-i) {
            None => (),
            Some(ch) => output.push(ch)
        }
    }
    
    // return output
    output
}
