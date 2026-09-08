#include "darts.h"

#include <array>

namespace darts {

int score(float x, float y) {
    struct Scoring {const float r2; const int points;};
    const std::array<Scoring, 3> SCORING {{{1, 10}, {25, 5}, {100, 1}}};
    auto rsquare = x*x + y*y;
    for (auto [r2, points] : SCORING) {
        if (rsquare <= r2) return points;
    }
    return 0;
}
    
}  // namespace darts
