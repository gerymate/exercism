-module(raindrops).

-export([convert/1]).


convert(Num) ->
    Raindrops = pling(Num) ++ plang(Num) ++ plong(Num),
    case Raindrops of
        [] -> integer_to_list(Num);
        _  -> Raindrops
    end.

pling(Num) when Num rem 3 =:= 0 -> "Pling";
pling(_) -> [].

plang(Num) when Num rem 5 =:= 0 -> "Plang";
plang(_) -> [].

plong(Num) when Num rem 7 =:= 0 -> "Plong";
plong(_) -> [].