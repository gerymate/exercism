pub fn raindrops(n: u32) -> String {
    let mut sound: String = Default::default();
    if n % 3 == 0 { sound += "Pling" }
    if n % 5 == 0 { sound += "Plang" }
    if n % 7 == 0 { sound += "Plong" }
    if sound.is_empty() { sound = format!("{n}") }
    sound
}
