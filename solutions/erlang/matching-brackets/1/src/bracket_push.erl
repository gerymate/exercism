-module(bracket_push).

-export([is_paired/1]).


is_paired(String) -> is_paired(String, [empty_stack]).

%%%

is_paired("", [empty_stack]) -> true;
is_paired("", [_Non,_Empty|_Stack]) -> false;
is_paired([Head|Tail], [NextExpected|RestExpected] = Stack) ->
  case Head of
    $( -> is_paired(Tail, [$) | Stack]);
    $[ -> is_paired(Tail, [$] | Stack]);
    ${ -> is_paired(Tail, [$} | Stack]);
    NextExpected -> is_paired(Tail, RestExpected);
    $) -> false;
    $] -> false;
    $} -> false;
    _  -> is_paired(Tail, Stack)
  end.

  
   
