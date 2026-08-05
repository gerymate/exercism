use std::collections::HashSet;

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut multiples = HashSet::new();
    for &n in factors {
        if n == 0 {
            multiples.insert(0);
            continue;
        }
        let mut m = 1;
        while m * n < limit {
            multiples.insert(m * n);
            m += 1;
        }
    }
    multiples.into_iter().sum()
    //    todo!("Sum the multiples of all of {factors:?} which are less than {limit}")

}
