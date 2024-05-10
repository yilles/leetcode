mod submit1;
mod submit2;
use std::time::Instant;

fn main() {
    let nums = vec![2, 3, 32423, 234234, 5435, 565463, 5656352, 5563, 34435, 700, 435435, 7465654, 45453, 65465, 435435, 45345, 354435, 63634533, 330, 60, 3232, 3300, 32200, 40043, 4322330, 4030, 2302402, 232434, 343400, 3200, 8, 9, 10, 11, 15, 7];
    let target = 9;

    let start = Instant::now();
    let mut result = None;
    for _i in 0..100 {
        result = submit1::two_sum(&nums, target);
    }
    let duration = start.elapsed();
    println!("Time elapsed is: {:?}", duration);
    match result {
        Some((i, j)) => println!("{} + {} = {}", nums[i], nums[j], target),
        None => println!("No value"),
    }

    let start = Instant::now();
    let mut result = None;
    for _i in 0..100 {
        result = submit2::two_sum(&nums, target);
    }
    let duration = start.elapsed();
    println!("Time elapsed is: {:?}", duration);
    match result {
        Some((i, j)) => println!("{} + {} = {}", nums[i], nums[j], target),
        None => println!("No value"),
    }
}
