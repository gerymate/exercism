/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let luhnize = |digit| { let double = 2*digit; if double > 9 {double - 9} else {double} };
    let chars = code
        .chars()
        .filter(|&ch| ch != ' ');
    if chars.clone().any(|ch| !ch.is_digit(10)) {return false}
    let (sum, len) = chars    
        .map(|ch| (ch as u8 - b'0') as u32)
        .rev()
        .enumerate()
        .map(|(i, digit)| if i%2 == 1 {luhnize(digit)} else {digit})
        .fold((0u32, 0u32), |(sum, len), digit| (sum + digit, len + 1));

    len > 1 && sum%10 == 0 
}
