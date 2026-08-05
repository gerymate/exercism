-module(anagram).

-export([find_anagrams/2]).


find_anagrams(Subject, Candidates) -> 
	[ Candidate || Candidate <- Candidates, 
								 is_anagram(string:lowercase(Subject), string:lowercase(Candidate)) ].


is_anagram(Word, Word) -> false;
is_anagram(Word, Subject) -> is_anagram0(Word, Subject).

is_anagram0([], []) -> true;
is_anagram0([], _) -> false;
is_anagram0(_, []) -> false;
is_anagram0([FirstLetter | Rest], Candidate) -> 
	lists:member(FirstLetter, Candidate) andalso 
	is_anagram0(Rest, lists:delete(FirstLetter, Candidate)).

