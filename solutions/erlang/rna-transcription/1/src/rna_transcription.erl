-module(rna_transcription).

-export([to_rna/1]).


to_rna([]) -> [];
to_rna([Head|Tail]) -> 
    [to_rna(Head) | to_rna(Tail)];
to_rna($C) -> $G;
to_rna($G) -> $C;
to_rna($T) -> $A;
to_rna($A) -> $U.