-module(queen_attack).

-export([can_attack/2]).


can_attack({WhiteRow, WhiteCol}, {BlackRow, BlackCol}) -> 
    WhiteRow == BlackRow orelse 
    WhiteCol == BlackCol orelse
    WhiteCol == BlackCol + WhiteRow - BlackRow orelse
    WhiteCol == BlackCol - WhiteRow + BlackRow.
