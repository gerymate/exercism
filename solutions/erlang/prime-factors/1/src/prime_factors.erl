-module(prime_factors).

-export([factors/1]).


factors(1) -> [];
factors(N) ->
    Max = ceil(math:sqrt(N)),    
    factors(N, [], primes_below(Max)).


factors(1, Factors, _) -> Factors;
factors(N, Factors, [Candidate|RestOfCandidates] = Candidates) ->
    case N rem Candidate =:= 0 of
        true -> factors(N div Candidate, [Candidate|Factors], Candidates);
        false -> factors(N, Factors, RestOfCandidates)
    end.

primes_below(N) -> 
    primes_below([], lists:seq(2,N)).

primes_below(Selected, []) -> lists:reverse(Selected);
primes_below(Selected, [Next|Candidates]) -> 
    primes_below([Next|Selected], lists:filter(fun(X) -> X rem Next /= 0 end, Candidates)).

