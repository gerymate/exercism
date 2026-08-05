#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace dna {

    typedef std::map<char, int> NucleotideStats; 

class counter {
    std::string strain;
public:
    counter(const std::string& strain);
    int count(char nucleotide) const;
    NucleotideStats nucleotide_counts() const;
private:
    static inline bool is_nucleotide(char ch);
};

}

#endif
