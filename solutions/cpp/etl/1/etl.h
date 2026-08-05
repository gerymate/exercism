#include <vector>
#include <map>
#include <locale>

class etl {
    typedef std::map<int, std::vector<char>> OldFormat;
    typedef std::map<char, int> NewFormat;
public:
    static NewFormat transform(const OldFormat& input) {
        NewFormat output;
        for (const auto& sameScoredLetters : input) {
            int score = sameScoredLetters.first;
            for (char letter : sameScoredLetters.second) {
                output[std::tolower(letter)] = score;
            }
        }
        return output;
    }
};

