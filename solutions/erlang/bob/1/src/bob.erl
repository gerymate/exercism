-module(bob).

-export([response/1]).

response(String) ->
    response_empty(is_empty(String), String).

response_empty(true, _) -> "Fine. Be that way!";
response_empty(false, UntrimmedString) ->
    String = string:trim(UntrimmedString), 
    response_yell(is_yell(String), String).

response_yell(true, String) ->
    response_yell_if_question(is_question(String));
response_yell(false, String) ->
    response_question(is_question(String)).

response_yell_if_question(false) -> "Whoa, chill out!";
response_yell_if_question(true) -> "Calm down, I know what I'm doing!".

response_question(true) -> "Sure.";
response_question(false) -> "Whatever.".

is_yell(String) -> 
    String =:= string:to_upper(String) andalso
    String =/= string:to_lower(String).

is_question(_String) ->
    $? == lists:last(_String).

is_empty([]) -> true;
is_empty(String) ->
    string:trim(String) == [].