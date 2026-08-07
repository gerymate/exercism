// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

const SECS_IN_EARTH_YEAR: f64 = 31557600.0;

#[derive(Debug)]
pub struct Duration(f64);

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration(s as f64 / SECS_IN_EARTH_YEAR)
    }
}

pub trait Planet {
    fn years_during(d: &Duration) -> f64;
}

macro_rules! make_planet {
    ($planet:ident, $year_ratio:expr) => {
        pub struct $planet;

        impl Planet for $planet {
            fn years_during(d: &Duration) -> f64 {
                d.0 / $year_ratio
            }
        }
    };
}

make_planet!(Mercury, 0.2408467);
make_planet!(Venus, 0.61519726);
make_planet!(Earth, 1.0);
make_planet!(Mars, 1.8808158);
make_planet!(Saturn, 29.447498);
make_planet!(Jupiter, 11.862615);
make_planet!(Uranus, 84.016846);
make_planet!(Neptune, 164.79132);
