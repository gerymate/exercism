use std::fmt;

#[derive(Debug, PartialEq)]
pub struct Clock {
    hours: i32,
    minutes: i32
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:0>2}:{:0>2}", self.hours, self.minutes)
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut hours_rem = minutes / 60;
        let mut ms = minutes % 60;
        if ms < 0 {
            ms += 60;
            hours_rem -= 1;
        }
        let hs = ((hours_rem + hours) % 24 + 24) % 24;
        Clock{ hours: hs, minutes: ms }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock::new(self.hours, self.minutes + minutes)
    }
}
