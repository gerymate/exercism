-module(run_length_encoding).

-export([decode/1, encode/1]).


decode("") -> "";
decode(String) -> decode(String, [], []).

encode("") -> "";
encode([Head | Tail]) -> encode(Tail, Head, 1, []).

%%%

encode("", Last, 1, Encoded) -> Encoded ++ [Last];
encode("", Last, N, Encoded) -> Encoded ++ integer_to_list(N) ++ [Last];
encode([Last|Tail], Last, N, Encoded) -> encode(Tail, Last, N + 1, Encoded);
encode([Head|Tail], Last, 1, Encoded) -> encode(Tail, Head, 1, Encoded ++ [Last]);
encode([Head|Tail], Last, N, Encoded) -> encode(Tail, Head, 1, Encoded ++ integer_to_list(N) ++ [Last]).

decode("", Decoded, "") -> Decoded;
decode([Head|Tail], Decoded, CountString) -> 
  case is_digit(Head) of
    true -> decode(Tail, Decoded, CountString ++ [Head]);
    false when CountString == "" -> decode(Tail, Decoded ++ [Head], "");
    false -> decode(Tail, Decoded ++ repeat(Head, list_to_integer(CountString)), "")
  end.

is_digit(Char) ->
  lists:any(fun(D) -> D == Char end, "0123456789").

repeat(_Item, 0) -> [];
repeat(Item, N) -> [Item|repeat(Item, N - 1)].


