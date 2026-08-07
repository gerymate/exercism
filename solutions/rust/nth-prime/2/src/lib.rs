pub fn nth(n: u32) -> u32 {
    let n = n as usize;
    let mut primes: Vec<u32> = Vec::with_capacity(n);
    primes.extend_from_slice(&[2, 3]);
    while primes.len() <= n {
        let mut candidate = *primes.last().unwrap() + 2;
        let mut sqrt_p = candidate.isqrt();
        while primes
            .iter()
            .take_while(|p| *p <= &sqrt_p)
            .any(|p| candidate % p == 0)
        {
            candidate += 2;
            sqrt_p = candidate.isqrt();
        }
        primes.push(candidate);
    }

    primes[n]
}
