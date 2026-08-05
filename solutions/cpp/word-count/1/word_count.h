#include <map>
#include <string>
#include <regex>
#include <algorithm>
#include <locale>

using std::string;

namespace word_count {

    typedef std::map<string, int> WordCount;

    void turn_lowercase(string& sentence) {
        for (auto& ch : sentence) ch = std::tolower(ch, std::locale());
    }

    void add_word(WordCount& word_count, string word) {
        turn_lowercase(word);
        const bool is_new_word { word_count.count(word) == 0 };
        if (is_new_word) {
            word_count[word] = 1;
        } else {
            ++word_count[word];
        }
    }

    WordCount words(const string& sentence) {
        WordCount word_count;
        const std::regex words_regex { "[\\w]+(?:'[\\w]+)?" };
        const auto words_begin {
            std::sregex_iterator(sentence.begin(), sentence.end(), words_regex)
        };
        const auto words_end { std::sregex_iterator() };
        const auto count_word {
            [&word_count](const std::smatch& match) 
                {add_word(word_count, match.str());}
        };

        std::for_each(words_begin, words_end, count_word);

        return word_count;
    }

}


