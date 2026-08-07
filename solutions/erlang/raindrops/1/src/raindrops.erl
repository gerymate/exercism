-module(raindrops).

-export([convert/1]).

-define(Divisible(Number, Divisor), Number rem Divisor =:= 0).
-define(Divisible(Number, D1, D2), 
    ?Divisible(Number, D1) andalso ?Divisible(Number, D2)).
-define(Divisible(Number, D1, D2, D3),
    ?Divisible(Number, D1, D2) andalso ?Divisible(Number, D3)).

convert(Num) ->
    if
        ?Divisible(Num, 3, 5, 7) ->
            "PlingPlangPlong";
        ?Divisible(Num, 3, 5) ->
            "PlingPlang";
        ?Divisible(Num, 3, 7) ->
            "PlingPlong";
        ?Divisible(Num, 5, 7) ->
            "PlangPlong";
        ?Divisible(Num, 3) ->
            "Pling";
        ?Divisible(Num, 5) ->
            "Plang";
        ?Divisible(Num, 7) ->
            "Plong";
        true ->
            integer_to_list(Num)
    end.