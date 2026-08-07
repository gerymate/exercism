#include "rna_transcription.h"

#include <algorithm>
#include <functional>

namespace rna_transcription {
  char to_rna(const char& nucleotid) {
    switch (nucleotid) {
      case 'G': return 'C'; break;
      case 'C': return 'G'; break;
      case 'A': return 'U'; break;
      case 'T': return 'A'; break;
      default: return ' ';
    }
  }

  std::string to_rna(const std::string& dna) {
    std::string rna(dna.size(), ' ');
    std::transform(
        begin(dna), end(dna), begin(rna), std::ref<char(const char&)>(to_rna));
    return rna;
  }
}  // namespace rna_transcription
