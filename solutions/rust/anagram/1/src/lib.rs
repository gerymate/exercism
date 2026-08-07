use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut output = HashSet::new();

    let low_case_word = word.to_lowercase();
    let mut word_sorted: Vec<char> = low_case_word.chars().collect();
    word_sorted.sort_unstable();
    
    for &candidate in possible_anagrams {
        let low_case_candidate = candidate.to_lowercase();
        let mut candidate_sorted: Vec<char> = low_case_candidate.chars().collect();
        candidate_sorted.sort_unstable();
        if word_sorted == candidate_sorted && low_case_word != low_case_candidate {
            output.insert(candidate);
        }
    }

    output
}
