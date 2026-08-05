-module(sublist).

-export([is_equal/2, is_sublist/2, is_superlist/2, is_unequal/2, relation/2]).

-spec is_equal(list(), list()) -> boolean().
is_equal(L1, L2) -> 
  is_sublist(L1, L2) andalso length(L1) == length(L2).

-spec is_sublist(list(), list()) -> boolean().
is_sublist(L1, L2) -> is_sublist0(L1, L2).

-spec is_superlist(list(), list()) -> boolean().
is_superlist(L1, L2) -> is_sublist(L2, L1).

-spec is_unequal(list(), list()) -> boolean().
is_unequal(L1, L2) -> not is_equal(L1, L2).

-spec relation(list(), list()) -> equal | unequal | sublist | superlist .
relation(L1, L2) -> 
  case {is_sublist(L1, L2), is_superlist(L1, L2)} of
    {true, true}   -> equal;
    {true, false}  -> sublist;
    {false, true}  -> superlist;
    {false, false} -> unequal
  end.

%%%

-spec is_sublist0(list(), list()) -> boolean().
is_sublist0([], []) -> true;
is_sublist0([], [_|_]) -> true;
is_sublist0([_|_], []) -> false;
is_sublist0([Head|Tail1]=List1, [Head|Tail2]) ->
  is_prefix(Tail1, Tail2) orelse is_sublist0(List1, Tail2);
is_sublist0([_Head1|_Tail1]=List1, [_Head2|Tail2]) ->
  is_sublist0(List1, Tail2).

-spec is_prefix(list(), list()) -> boolean().
is_prefix([], []) -> true;
is_prefix([], [_|_]) -> true;
is_prefix([_|_], []) -> false;
is_prefix([Head|Tail1], [Head|Tail2]) ->
  is_prefix(Tail1, Tail2);
is_prefix([_Head1|_], [_Head2|_]) -> false.

