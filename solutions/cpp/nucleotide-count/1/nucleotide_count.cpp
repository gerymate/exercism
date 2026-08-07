#include "nucleotide_count.h"
#include <algorithm>
#include <stdexcept>

namespace dna {

counter::counter(const std::string& strain) : strain{strain} {
   if (!all_of(strain.begin(), strain.end(), is_nucleotide))
        throw std::invalid_argument{""};
}

int counter::count(char nucleotide) const {
    if (!is_nucleotide(nucleotide)) throw std::invalid_argument{""};
    return std::count(strain.begin(), strain.end(), nucleotide); 
}

NucleotideStats counter::nucleotide_counts() const {
    NucleotideStats stats { {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };
    for (char nucleotide : strain) ++stats[nucleotide];
    return stats;
}

bool counter::is_nucleotide(char ch) {
    return ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G';
}
 
}

