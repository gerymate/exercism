-module(difference_of_squares).

-export([difference_of_squares/1, square_of_sum/1, sum_of_squares/1]).

-spec difference_of_squares(pos_integer()) -> pos_integer().
difference_of_squares(N) -> square_of_sum(N) - sum_of_squares(N).

-spec square_of_sum(pos_integer()) -> pos_integer().
square_of_sum(N) -> 
  Sum = N * (N + 1) div 2,
  Sum * Sum.

-spec sum_of_squares(pos_integer()) -> pos_integer().
sum_of_squares(N) -> 
  lists:foldl(fun(X, Acc) -> Acc + X*X end, 0, lists:seq(1, N)).
  
