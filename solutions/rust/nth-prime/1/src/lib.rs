pub fn nth(n: u32) -> u32 {
    let mut primes: Vec<u32> = vec![2];
    while primes.len() <= n.try_into().unwrap() {
        let mut candidate = *primes.last().unwrap() + 1;
        while primes.iter().any(|p| candidate % p == 0) {
            candidate += 1;
        }
        primes.push(candidate);
    }

    *primes.last().unwrap()
}
