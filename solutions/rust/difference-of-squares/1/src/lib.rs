pub fn square_of_sum(n: u32) -> u32 {
    (1..=n).fold(0, u32::saturating_add).pow(2)
}

pub fn sum_of_squares(n: u32) -> u32 {
    (1..=n).map(|n| n * n).fold(0, u32::saturating_add)
}

pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}
