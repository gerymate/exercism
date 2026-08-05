pub fn egg_count(display_value: u32) -> usize {
    let mut bits : usize = 0;
    let mut mask : u32 = 1;
    for n in 1..32 {
        if (display_value & mask) > 0 {
            bits += 1;
        }
        mask <<= 1;
    }
    bits
}
