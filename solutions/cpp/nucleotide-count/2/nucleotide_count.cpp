#include "nucleotide_count.h"
#include <algorithm>
#include <stdexcept>

namespace dna {

counter::counter(const std::string& strain)
    : nucleotideStats{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} } {
    for (char nucleotide : strain) {
        if (!is_nucleotide(nucleotide)) throw std::invalid_argument{""};
        ++nucleotideStats[nucleotide];
    }
}

int counter::count(char nucleotide) const {
    if (!is_nucleotide(nucleotide)) throw std::invalid_argument{""};
    return nucleotideStats.at(nucleotide); 
}

counter::NucleotideStats counter::nucleotide_counts() const {
    return nucleotideStats;
}

bool counter::is_nucleotide(char ch) {
    return ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G';
}
 
}

