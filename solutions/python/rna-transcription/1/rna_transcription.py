def to_rna(dna_strand):
    transcription = dict(G='C', C='G', T='A', A='U')
    return ''.join([transcription[nucleotide] for nucleotide in dna_strand])
