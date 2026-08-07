pub fn production_rate_per_hour(speed: u8) -> f64 {
    let base_production = 221.0 * speed as f64;
    let failures: i32 = match speed {
        1..=4 => 100,
        5..=8 => 90,
        _ => 77,
    };
    base_production * failures as f64 * 0.01
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    production_rate_per_hour(speed) as u32 / 60
}
