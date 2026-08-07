#include "scrabble_score.h"
#include<unordered_map>
#include<utility>
#include<vector>
#include<locale>

namespace scrabble_score {
  typedef std::pair<std::string, int> score_record_t;
  const std::vector<score_record_t> letter_data {
    {"aeioulnrst", 1},
    {"dg", 2}, 
    {"bcmp", 3},
    {"fhvwy", 4},
    {"k", 5},
    {"jx", 8},  
    {"qz", 10} 
  };

  typedef std::unordered_map<char, int> score_table_t;
  score_table_t get_score_table() {
    score_table_t score_table;
      for (const score_record_t& score_class : letter_data) {
        for (const auto& letter : score_class.first) {
          score_table[letter] = score_class.second;
        }
      }
    return score_table;   
  }

  int score(const std::string& word) {
    int value {0};
    score_table_t score_table {get_score_table()};
    for (const auto& letter : word) {
      value += score_table.at(std::tolower(letter));
    }
    return value;
  }
}  // namespace scrabble_score
