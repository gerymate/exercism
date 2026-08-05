#include<vector>
#include<string>

using namespace std;

struct food_chain {
  static string verse(int n) {    
    static vector<string> animals = {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
    static vector<string> second_line = {
      "",
      "It wriggled and jiggled and tickled inside her.\n",
      "How absurd to swallow a bird!\n",
      "Imagine that, to swallow a cat!\n",
      "What a hog, to swallow a dog!\n",
      "Just opened her throat and swallowed a goat!\n",
      "I don't know how she swallowed a cow!\n",
      "She's dead, of course!\n"
    };
    string text = "I know an old lady who swallowed a " + animals.at(n-1) + ".\n"
                + second_line.at(n-1);
    if (n == 8) return text;
    for (int i = n-1; i > 0; --i) {
      text += swallowed_to_catch(animals.at(i), animals.at(i-1));
    }
    return text 
         + "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  }

  static string verses(int first, int last) {
    string text;
    for (int i = first; i <= last; ++i) text += verse(i) + "\n";
    return text;
  }

  static string sing() {
    return verses(1, 8);
  }

  private:

  static string swallowed_to_catch(string first, string second) {
    string line = "She swallowed the " + first + " to catch the " + second;
    if (second == "spider") line += " that wriggled and jiggled and tickled inside her";
    return line + ".\n";
  }

};