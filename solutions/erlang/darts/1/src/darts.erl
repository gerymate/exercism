-module(darts).

-export([score/2]).


score(X, Y) -> score_distance_squared(X * X + Y * Y).

score_distance_squared(RR) when RR > 10 * 10 -> 0;
score_distance_squared(RR) when RR > 5 * 5 -> 1;
score_distance_squared(RR) when RR > 1 -> 5;
score_distance_squared(_RR) -> 10.
