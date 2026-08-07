#include "isogram.h"
#include <unordered_set>
#include <locale>

bool isogram::is_isogram(const std::string& input) {
    std::unordered_set<char> charactersEncountered;
    for (auto ch : input) {
        if (ch == '-' || ch == ' ')
            continue;
        auto lowerCaseCH {std::tolower(ch)};
        if (charactersEncountered.count(lowerCaseCH) == 0) {
            charactersEncountered.insert(lowerCaseCH);
        } else {
            return false;
        }
    }
    return true;
}

