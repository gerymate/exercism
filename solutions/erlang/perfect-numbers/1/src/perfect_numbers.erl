-module(perfect_numbers).

-export([classify/1]).


classify(Number) when Number < 1 -> error(nonnatural);
classify(Number) -> 
	Aliquot_sum = aliquot_sum(Number),
	if
		Aliquot_sum < Number -> deficient;
		Aliquot_sum > Number -> abundant;
		true -> perfect
	end.

aliquot_sum(N) -> aliquot_sum(N, 1, 0).

aliquot_sum(N, D, Sum) when 2 * D > N -> Sum;
aliquot_sum(N, D, Sum) when N rem D == 0 -> aliquot_sum(N, D + 1, Sum + D);
aliquot_sum(N, D, Sum) -> aliquot_sum(N, D + 1, Sum).

