-module(hamming).

-export([distance/2]).


distance(Strand1, Strand2) -> distance(Strand1, Strand2, 0).


distance([], [], Sum) -> Sum;
distance([], _Strand, _) -> strand_size_mismatch_error();
distance(_Strand, [], _) -> strand_size_mismatch_error();
distance([Head1|Tail1], [Head2|Tail2], Sum) ->
    case Head1 == Head2 of
        true -> distance(Tail1, Tail2, Sum);
        false -> distance(Tail1, Tail2, Sum + 1)
    end.

strand_size_mismatch_error() ->
    {error, "left and right strands must be of equal length"}.
