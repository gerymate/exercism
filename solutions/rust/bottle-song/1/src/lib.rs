fn pluralize(word: &str) -> &str {
    match word {
        "One" | "one" => "",
        _ => "s",
    }
}

fn verse(start_bottles: u32) -> String {
    const CAP_WORDS: [&str; 11] = [
        "No", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    ];
    const UNCAP_WORDS: [&str; 11] = [
        "no", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    ];
    let first_word = CAP_WORDS[start_bottles as usize];
    let second_word = UNCAP_WORDS[start_bottles as usize - 1];
    format!(
        r#"{0} green bottle{2} hanging on the wall,
{0} green bottle{2} hanging on the wall,
And if one green bottle should accidentally fall,
There'll be {1} green bottle{3} hanging on the wall."#,
        first_word,
        second_word,
        pluralize(first_word),
        pluralize(second_word)
    )
}

pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let mut bottles = start_bottles;
    let end_bottles = start_bottles - take_down + 1;
    let mut result = String::new();
    loop {
        result += &verse(bottles);
        if bottles == end_bottles {
            break;
        } else {
            result += "\n\n";
            bottles -= 1;
        }
    }
    result
}
