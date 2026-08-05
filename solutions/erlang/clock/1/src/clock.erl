-module(clock).

-export([create/2, is_equal/2, minutes_add/2, to_string/1]).

-type clock_type() :: {0..23, 0..60}.

-spec(create(integer(), integer()) -> clock_type()).
create(Hour, Minute) -> 
  TotalMinutes = ((Hour * 60 + Minute) rem 1440 + 1440) rem 1440, 
  Hours = TotalMinutes div 60,
  Minutes = TotalMinutes rem 60,
  {Hours, Minutes}.

-spec(is_equal(clock_type(), clock_type()) -> boolean()).
is_equal(Clock1, Clock2) -> Clock1 == Clock2.

-spec(minutes_add(clock_type(), integer()) -> clock_type()).
minutes_add({Hour, Minute}, Minutes) -> create(Hour, Minute + Minutes).

-spec(to_string(clock_type()) -> string()).
to_string({Hour, Minute}) -> 
  lists:flatten(
    io_lib:format("~2..0B:~2..0B" , [Hour, Minute])
  ).


