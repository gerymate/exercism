-module(diamond).

-export([rows/1]).


rows("A") -> ["A"];
rows("B") -> [" A ", "B B", " A "];
rows([LastChar]) ->
  [terminal_row(LastChar)] ++ intermediate_rows($B, LastChar, []) ++ [terminal_row(LastChar)].

%

terminal_row(Ch) ->
  Indentation = Ch - $A,
  Spaces = spaces(Indentation),
  Spaces ++ "A" ++ Spaces.

intermediate_rows(LastChar, LastChar, Res) ->
  lists:reverse(Res) ++ [row_for(LastChar, LastChar)] ++ Res;
intermediate_rows(Ch, LastChar, Res) when Ch < LastChar ->
      intermediate_rows(Ch + 1, LastChar, [row_for(Ch, LastChar)|Res]).

row_for(Ch, LastChar) ->
  Indentation = LastChar - Ch,
  OuterSpaces = spaces(Indentation),
  NumOfSpacesBetween = 2 * (Ch - $A) - 1, 
  InnerSpaces = spaces(NumOfSpacesBetween),
  Row = OuterSpaces ++ [Ch] ++ InnerSpaces ++ [Ch] ++ OuterSpaces,
  Row.

spaces(0) -> "";
spaces(N) when N > 0 -> [$\s | spaces(N - 1)].


