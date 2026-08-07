pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let m = minefield.len();
    let mut scoring = Vec::<String>::with_capacity(m);
    if m==0 {
        return scoring
    }
    let n = minefield[0].len();
    for i in 0..m {
        let mut line = String::with_capacity(n);
        for j in 0..n {
            line.push(neighbours(i, j, minefield));
        }
        scoring.push(line);
    }
    scoring
}

fn neighbours(i: usize, j: usize, mf: &[&str]) -> char {
    let line = mf[i].as_bytes();
    if line[j] == '*' as u8 {
        return '*'
    }
    let m = mf.len();
    let n = mf[i].len();
    let mut mines = 0i32;

    let mines_in = |row: &[u8], col: usize| {
        let mut sum = 0i32;
        if col > 0 && row[col-1] == '*' as u8 {
                sum+=1;
        }
        if row[col] == '*' as u8 {
            sum+=1;
        }
        if col+1 < n && row[j+1] == '*' as u8 {
            sum+=1;
        }
        sum
    };
    // count over
    if i > 0 {
        let over = mf[i-1].as_bytes();
        mines += mines_in(over, j)
    }
    // count line
    mines += mines_in(line, j);
    // count below
    if i+1 < m {
        let below = mf[i+1].as_bytes();
        mines += mines_in(below, j)
    }

    match mines {
        0 => ' ',
        1 => '1',
        2 => '2',
        3 => '3',
        4 => '4',
        5 => '5',
        6 => '6',
        7 => '7',
        8 => '8',
        _ => 'E',
    }
}
