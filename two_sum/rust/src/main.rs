mod submit1;
use submit1::two_sum;

fn main() {
    let nums = vec![2, 7, 11, 15];
    let target = 9;
    let result = two_sum(&nums, target);
    match result {
        Some((i, j)) => println!("{} + {} = {}", nums[i], nums[j], target),
        None => println!("No value"),
    }
}