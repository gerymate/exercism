-module(prime_factors).

-export([factors/1]).


factors(1) -> [];
factors(N) when N > 1 -> factors(N, 2, []).


factors(1, _, Factors) -> Factors;
factors(N, Candidate, Factors) when N rem Candidate == 0 ->
    factors(N div Candidate, Candidate, [Candidate | Factors]);
factors(N, Candidate, Factors) ->
    factors(N, Candidate + 1, Factors).
