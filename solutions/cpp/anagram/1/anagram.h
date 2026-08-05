#ifndef ANAGRAM_H
#define ANAGRAM_H

#include<string>
#include<vector>

namespace anagram {

typedef std::vector<std::string> WordList;

class anagram {
    std::string baseWord;
    std::string charsSorted;
public:
    anagram(const std::string&);
    WordList matches(const WordList&);
private:
    bool is_my_anagram(std::string);
    static void make_lowercase(std::string&);
};

}

#endif

