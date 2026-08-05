-module(phone_number).

-export([number/1, areacode/1, pretty_print/1, test_version/0]).

number(String) ->
  JustTheDigits = lists:filter(fun is_digit/1, String),
  NumberOfDigits = length(JustTheDigits),
  FirstDigit = hd(JustTheDigits),
  TooFewOrMuchDigits = NumberOfDigits < 10 orelse NumberOfDigits > 11,
  HasCountryCode = NumberOfDigits == 11,
  BadCountryCode = HasCountryCode andalso FirstDigit =/= $1, 
  if
    TooFewOrMuchDigits orelse BadCountryCode ->
      "0000000000";
    HasCountryCode ->
      tl(JustTheDigits);
    true -> 
      JustTheDigits
  end.

areacode(String) ->
  lists:sublist(number(String), 3).

pretty_print(String) ->
  Number = number(String),
  "(" ++ lists:sublist(Number, 3) ++ ") "
      ++ lists:sublist(Number, 4, 3) ++ "-" 
      ++ lists:sublist(Number, 7, 10).

test_version() -> 1.

%%

is_digit(_C) when _C==$0;_C==$1;_C==$2;_C==$3;_C==$4;
                  _C==$5;_C==$6;_C==$7;_C==$8;_C==$9 -> true;
is_digit(_) -> false.


