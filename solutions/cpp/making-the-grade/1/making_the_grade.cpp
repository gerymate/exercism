#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> int_scores;
    int_scores.reserve(student_scores.size());
    for (auto score: student_scores) {
        int_scores.emplace_back(static_cast<int>(score));
    }
    return int_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (auto score : student_scores) {
        if (score <= 40) count++;
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    auto diff = (highest_score - 40) / 4;
    return std::array<int, 4> {41, 41 + diff, 41 + 2*diff, 41 + 3*diff};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking;
    ranking.reserve(student_scores.size());
    for (auto i=0; i != student_scores.size(); i++) {
        std::string rank_item;
        rank_item.reserve(student_names.at(i).size() + 11);  // efficient up to 99999 students
        rank_item += std::to_string(i+1);
        rank_item += ". ";
        rank_item += student_names.at(i);
        rank_item += ": ";
        rank_item += std::to_string(student_scores.at(i));
        ranking.emplace_back(rank_item);
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (auto i=0; i!=student_scores.size(); i++) {
        if (student_scores.at(i) == 100) return student_names.at(i);
    }
    return "";
}
