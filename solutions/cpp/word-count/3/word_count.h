#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <map>
#include <string>
#include <regex>
#include <algorithm>
#include <locale>

namespace word_count {

    using std::string;

    typedef std::map<string, int> WordCount;

    inline string&& turn_lowercase(string&& phrase) {
        for (auto& ch : phrase) ch = std::tolower(ch, std::locale());
        return std::move(phrase);
    }

    inline WordCount words(const string& sentence) {
        WordCount word_count;
        const std::regex words_regex { "[\\w]+(?:'[\\w]+)?" };

        const auto words_begin {
            std::sregex_iterator(sentence.begin(), sentence.end(), words_regex)
        };
        const auto words_end { std::sregex_iterator() };

        const auto count_word {
            [&word_count](const std::smatch& match) 
                {++word_count[turn_lowercase(match.str())];}
        };

        std::for_each(words_begin, words_end, count_word);

        return word_count;
    }

}

#endif

