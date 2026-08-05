-module(strain).

-export([keep/2, discard/2]).

keep(_, []) -> [];
keep(Fn, [Head | _] = List) ->
  keep(Fn(Head), Fn, List).

keep(true, Fn, [Head | Tail]) ->
  [Head | keep(Fn, Tail)];
keep(false, Fn, [_ | Tail]) ->
  keep(Fn, Tail).
 
discard(Fn, List) ->
  NotFn = fun(X) -> not Fn(X) end,
  keep(NotFn, List).
