#pragma once
#include <string>

namespace atbash_cipher {
    using std::string;

    string encode(const string& in);
    string decode(const string& in);
    
}  // namespace atbash_cipher
