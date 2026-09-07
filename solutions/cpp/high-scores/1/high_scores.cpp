#include "high_scores.h"

#include <algorithm>
#include <numeric>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return *scores.rbegin();
}

int HighScores::personal_best() {
    return *max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    auto result = std::accumulate(
        scores.begin(), scores.end(), std::vector{0, 0, 0},
        [](std::vector<int>top3, auto candidate){
            for (auto it = top3.begin(); it != top3.end(); it++){
                if (candidate >= *it) {
                    top3.insert(it, candidate);
                    top3.pop_back();
                    break;
                }
            }
            return top3;
        });
    result.resize(std::min(std::vector<int>::size_type{3}, scores.size()));
    return result;
}

}  // namespace arcade
