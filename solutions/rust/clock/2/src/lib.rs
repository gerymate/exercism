use std::fmt;

#[derive(Debug, PartialEq)]
pub struct Clock {
    minutes: i32
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:0>2}:{:0>2}", self.minutes / 60, self.minutes % 60)
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let ms = (hours * 60 + minutes).rem_euclid(24 * 60);
        Clock{ minutes: ms }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Clock::new(self.minutes / 60, self.minutes % 60 + minutes)
    }
}
