-module(bob).

-export([response/1]).

response(String) ->
    Trimmed = string:trim(String),
    Is_empty = Trimmed == [],
    Is_yell = is_yell(Trimmed),
    Is_question = is_question(Trimmed),
    if
        Is_empty -> "Fine. Be that way!";
        Is_yell and Is_question -> "Calm down, I know what I'm doing!"; 
        Is_yell -> "Whoa, chill out!";
        Is_question -> "Sure.";
        true -> "Whatever."
    end.

is_yell(String) -> 
    String =:= string:to_upper(String) andalso
    String =/= string:to_lower(String).

is_question([]) -> false;
is_question(_String) ->
    $? == lists:last(_String).
