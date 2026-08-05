-module(pangram).

-export([is_pangram/1]).

-define(ALPHABET, "abcdefghijklmnopqrstuvwxyz").

is_pangram([]) -> false;
is_pangram(String) -> contains_each(String, ?ALPHABET).

contains_each(_, []) -> true;
contains_each([], _Alphabet) -> false;
contains_each([FirstLetter | RestOfString], Alphabet) ->
    LowerCaseFirstLetter = hd(string:lowercase([FirstLetter])),
    ContainsFirstLetter = lists:member(LowerCaseFirstLetter, Alphabet),
    case ContainsFirstLetter of
        true -> contains_each(RestOfString, lists:delete(LowerCaseFirstLetter, Alphabet));
        false -> contains_each(RestOfString, Alphabet)
    end.

