#ifndef BOB_H
#define BOB_H

#include <string>
#include <locale>
#include <algorithm>

namespace bob {
    using std::string;
    using std::all_of;
    using std::any_of;
    using std::begin;
    using std::end;
    using std::toupper;
    using std::isalpha;
    using std::isspace;
    using std::locale;

    // functions defined from bottom to top

    inline bool is_question(const string& sentence) {
        return '?' == sentence.back();
    }

    inline bool is_yell (const string& sentence) {
        const bool all_uppercase { all_of(begin(sentence), end(sentence), [](char ch){return ch == toupper(ch, locale());}) };
        const bool has_letters { any_of(begin(sentence), end(sentence), [](char ch){return isalpha(ch, locale());}) };
        return all_uppercase && has_letters;
    }

    inline void right_trim(string& sentence) {
        while (!sentence.empty() && isspace(sentence.back(), locale()))
            sentence.pop_back();
    }

    inline string hey(string sentence) {
        right_trim(sentence);
        if (sentence.empty()) return "Fine. Be that way!";
        const bool yell {is_yell(sentence)};
        const bool question {is_question(sentence)};
        if (yell && question) return "Calm down, I know what I'm doing!";
        if (yell) return "Whoa, chill out!";
        if (question) return "Sure.";
        return "Whatever.";
    }

}

#endif

