use core::panic;
use std::fs;

fn main() {
    let input: String = match fs::read_to_string("src/input1.txt") {
        Ok(content) => content,
        Err(e) => panic!("{}", e),
    };

    let rows: Vec<&str> = input.split("\n").collect();
    let mut col1: Vec<i32> = Vec::new();
    let mut col2: Vec<i32> = Vec::new();

    for row in rows {
        let res: Vec<&str> = row.split("   ").collect();
        if row != "" {
            col1.push(res[0].parse().unwrap());
            col2.push(res[1].parse().unwrap());
        }
    }

    col1.sort();
    col2.sort();

    let mut ans = 0;
    let mut i = 0;
    while i < col1.len() {
        if col1[i] > col2[i] {
            ans += col1[i] - col2[i]
        } else {
            ans += col2[i] - col1[i]
        }
        i += 1;
    }

    println!("answer: {}", ans);
}
