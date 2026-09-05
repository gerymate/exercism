#include "atbash_cipher.h"
#include <unordered_map>
#include <locale>

namespace atbash_cipher {
    const std::string ALPHABET { "abcdefghijklmnopqrstuvwxyz" };

    std::unordered_map<char, char> encoder() {
        std::unordered_map<char, char> enc;
        for (auto i=0; i != 26; i++) {
            enc[ALPHABET[i]] = ALPHABET[25-i];
        }
        return enc;
    }

    std::unordered_map<char, char> decoder() {
        std::unordered_map<char, char> dec;
        for (auto i=0; i != 26; i++) {
            dec[ALPHABET[25-i]] = ALPHABET[i];
        }
        return dec;
    }
    
    string encode(const string& in) {
        std::unordered_map enc {encoder()};
        string out;
        auto counter { 0 };
        for (const auto& ch : in) {
            if (std::isalnum(ch)) {
                if (counter > 0 && counter % 5 == 0) {
                    out += ' ';
                }
                if (isalpha(ch)) {
                    out += enc[std::tolower(ch)];
                } else {
                    out += ch;
                }
                counter++;
            }
        }
        return out;
    }
    
    string decode(const string& in) {
        std::unordered_map dec {decoder()};
        string out;
        for (const auto& ch : in) {
            if (isalpha(ch)) {
                out += dec[ch];
            } else if (isdigit(ch)) {
                out += ch;
            }
        }
        return out;
    }
}  // namespace atbash_cipher
