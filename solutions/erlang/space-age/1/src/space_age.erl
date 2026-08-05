-module(space_age).

-export([age/2]).


age(_Planet, _Seconds) -> 
    _Seconds / earth_seconds_a_year() / orbital_period(_Planet).


earth_seconds_a_year() -> 31557600.

orbital_period(mercury) -> 0.2408467 ;
orbital_period(venus) -> 0.61519726 ;
orbital_period(earth) -> 1 ;
orbital_period(mars) -> 1.8808158 ;
orbital_period(jupiter) -> 11.862615 ;
orbital_period(saturn) -> 29.447498 ;
orbital_period(uranus) -> 84.016846 ;
orbital_period(neptune) -> 164.79132 .