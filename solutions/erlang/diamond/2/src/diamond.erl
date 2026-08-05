-module(diamond).

-export([rows/1]).


rows("A") -> ["A"];

rows("B") -> [" A ", 
              "B B", 
              " A "];

rows([Ch]) ->
  UpperDiamond = 
    first_row(Ch) ++
    intermediate_rows(Ch),
  LowerDiamond = 
    lists:reverse(UpperDiamond),
  FullDiamond =
    UpperDiamond ++ middle_row(Ch) ++ LowerDiamond,
  FullDiamond.

%

first_row(Ch) ->
  Indentation = Ch - $A, 
  Sps = spaces(Indentation),
  [Sps ++ "A" ++ Sps].

intermediate_rows(LastChar) -> intermediate_rows($B, LastChar).
intermediate_rows(LastChar, LastChar) ->
  [];
intermediate_rows(CurrentChar, LastChar) when CurrentChar < LastChar ->
  [row_for(CurrentChar, LastChar) | intermediate_rows(CurrentChar + 1, LastChar)].

middle_row(Ch) ->
  [row_for(Ch, Ch)].

row_for(Ch, LastChar) ->
  Width = (LastChar - $A) * 2 + 1,
  Indentation = LastChar - Ch,
  SpacesOutside = spaces(Indentation),
  NumOfSpacesBetween = Width - (2 * Indentation) - 2, 
  FullRow = SpacesOutside ++ [Ch] ++ spaces(NumOfSpacesBetween) ++ [Ch] ++ SpacesOutside,
  FullRow.

spaces(0) -> [];
spaces(N) when N > 0 -> [$\s | spaces(N - 1)].


