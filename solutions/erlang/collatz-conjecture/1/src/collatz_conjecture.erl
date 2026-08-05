-module(collatz_conjecture).

-export([steps/1]).

steps(N) when N < 1 -> {error, "Only positive numbers are allowed"};
steps(N) -> steps(N, 0).


steps(1, Steps) -> Steps;
steps(N, Steps) when N rem 2 =:= 0 -> steps(N div 2, Steps + 1);
steps(N, Steps) -> steps(N * 3 + 1, Steps + 1).

