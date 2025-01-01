use std::fs;

fn check_report(report: Vec<i32>) -> bool {
    for level in report {
        // TODO: check if safe or not
    }
    return true;
}

fn get_input_string(filepath: &str) -> String {
    let input: String = match fs::read_to_string(filepath) {
        Ok(content) => content,
        Err(e) => panic!("{}", e),
    };
    return input;
}

fn main() {
    let input_str = get_input_string("src/input1.txt");
    let reports: Vec<&str> = input_str.split("\n").collect();

    let mut safe_report_count = 0;

    for report in reports {
        if report != "" {
            // create a i32 array from report string
            let mut report_vec: Vec<i32> = Vec::new();
            // let mut number_str: &str = "";
            // let mut idx: i32 = 0;
            // while (idx as usize) < report.len() {
            //     let str_data = String::from(report);
            //     if (str_data[0] == " ") {
            //         report_vec.push(number_str.parse().unwrap());
            //         number_str = "";
            //     } else {
            //         number_str += str_data[idx];
            //     }
            //     idx += 1;
            // }

            let mut a = report.split_whitespace();
            print!("{}\n", a.next().unwrap());


            if check_report(report_vec) {
                safe_report_count += 1;
            }
        }
    }
    println!("{}", safe_report_count);
}
