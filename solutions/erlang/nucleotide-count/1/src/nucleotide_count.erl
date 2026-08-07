-module(nucleotide_count).

-export([count/2, nucleotide_counts/1]).


count(Strand, Nucleotide) -> count(Strand, Nucleotide, 0).

nucleotide_counts(Strand) -> nucleotide_counts(Strand, 0, 0, 0, 0).

%%%%

count([], _, N) -> N;
count([Head | Tail], [Head], N) -> count(Tail, [Head], N + 1);
count([Head | Tail], Nucleotide, N) 
  when Head == $A orelse Head == $C orelse Head == $G orelse Head == $T -> 
    count(Tail, Nucleotide, N).

nucleotide_counts([], A, C, G, T) -> [{"A", A}, {"C", C}, {"G", G}, {"T", T}];
nucleotide_counts([$A | Tail], A, C, G, T) -> nucleotide_counts(Tail, A+1, C, G, T);
nucleotide_counts([$C | Tail], A, C, G, T) -> nucleotide_counts(Tail, A, C+1, G, T);
nucleotide_counts([$G | Tail], A, C, G, T) -> nucleotide_counts(Tail, A, C, G+1, T);
nucleotide_counts([$T | Tail], A, C, G, T) -> nucleotide_counts(Tail, A, C, G, T+1).


