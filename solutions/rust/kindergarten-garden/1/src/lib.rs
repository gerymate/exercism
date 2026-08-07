const KIDS: [&str; 12] = [
    "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph",
    "Kincaid", "Larry",
];

pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let index = KIDS.binary_search(&student).expect("kid not found");
    let (line1, line2) = diagram
        .split_once("\n")
        .expect("there's no two rows of plants");
    let mut iter1 = line1.chars().skip(2 * index);
    let a = iter1.next().expect("plant missing");
    let b = iter1.next().expect("plant missing");
    let mut iter2 = line2.chars().skip(2 * index);
    let c = iter2.next().expect("plant missing");
    let d = iter2.next().expect("plant missing");

    [a, b, c, d].iter().map(identify_plants).collect()
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
