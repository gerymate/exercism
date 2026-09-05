#include "rotational_cipher.h"
#include <string>
#include <locale>

namespace rotational_cipher {

const std::string UPPER {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const std::string LOWER {"abcdefghijklmnopqrstuvwxyz"};

std::string rotate(const std::string& in, int shift) {
    std::string out;
    for (const auto ch : in) {
        if (islower(ch)) {
            auto n = (LOWER.find(ch) + shift) % 26;
            out += LOWER.at(n);
        } else if (isupper(ch)) {
            auto n = (UPPER.find(ch) + shift) % 26;
            out += UPPER.at(n);
        } else {
            out += ch;
        }
    }
    return out;
}
    
}  // namespace rotational_cipher
