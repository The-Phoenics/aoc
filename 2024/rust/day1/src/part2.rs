use std::{collections::HashMap, fs};

fn get_input_string(filepath: &str) -> String {
    let input: String = match fs::read_to_string(filepath) {
        Ok(content) => content,
        Err(e) => panic!("{}", e),
    };
    return input;
}

fn main() {
    let input_str = get_input_string("src/input2.txt");
    let rows: Vec<&str> = input_str.split("\n").collect();

    let mut left_col: Vec<i32> = Vec::new();
    let mut right_col_hashmap: HashMap<i32, i32> = HashMap::new();

    for row in rows {
        if row != "" {
            let data: Vec<&str> = row.split("   ").collect();
            let left_val: i32 = data[0].parse().unwrap();
            left_col.push(left_val);

            let right_val: i32 = data[1].parse().unwrap();
            match right_col_hashmap.get_key_value(&right_val) {
                Some(value) => {
                    right_col_hashmap.insert(*value.0, *value.1 + 1);
                }
                None => {
                    right_col_hashmap.insert(right_val, 1);
                }
            }
        }
    }

    let mut ans = 0;
    for n in left_col {
        match right_col_hashmap.get_key_value(&n) {
            Some(value) => {
                ans += value.0 * value.1;
            }
            None => {}
        }
    }
    println!("answer: {}", ans)
}
