pub fn is_armstrong_number(num: u32) -> bool {
    if num == 0 {
        return true;
    }

    let mut num_copy = num;
    let mut digits: Vec<u32> = vec![];
    while num_copy > 0 {
        digits.push(num_copy % 10);
        num_copy /= 10;
    }

    let n = digits.len() as u32;

    num as u128 == digits.iter().map(|&d| (d as u128).pow(n)).sum()
}
