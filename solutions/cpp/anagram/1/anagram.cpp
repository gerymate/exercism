#include "anagram.h"
#include<algorithm>
#include<functional>
#include<locale>

using namespace std;

namespace anagram {

    anagram::anagram(const string& word) : baseWord{word} {
        make_lowercase(baseWord);
        charsSorted = baseWord;
        sort(begin(charsSorted), end(charsSorted));
    }

    WordList anagram::matches(const WordList& words) {
        WordList anagrams;
        copy_if(begin(words), end(words), back_inserter(anagrams), 
                bind(&anagram::is_my_anagram, this, placeholders::_1));
        return anagrams;
    }

    bool anagram::is_my_anagram(string word) {
        make_lowercase(word);
        if (word == baseWord) return false;
        sort(begin(word), end(word));
        return word == charsSorted;
    }

    void anagram::make_lowercase(string& word) {
        transform(begin(word), end(word), begin(word),
                bind(tolower<char>, placeholders::_1, locale()));
    }
}

