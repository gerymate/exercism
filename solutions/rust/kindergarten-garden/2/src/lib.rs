const KIDS: [&str; 12] = [
    "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph",
    "Kincaid", "Larry",
];

pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let index = KIDS.binary_search(&student).expect("kid not found");
    diagram
        .lines()
        .flat_map(|line| line.chars().skip(2 * index).take(2))
        .map(identify_plants)
        .collect()
}

fn identify_plants(encoding: &char) -> &'static str {
    match encoding {
        'G' => "grass",
        'V' => "violets",
        'C' => "clover",
        'R' => "radishes",
        _ => panic!("oh, no! there's no such plant!"),
    }
}
