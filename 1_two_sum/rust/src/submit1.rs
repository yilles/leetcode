pub fn two_sum(nums: &Vec<i32>, target: i32) -> Option<(usize, usize)> {
    for i in 0..nums.len() {
        for j in i + 1..nums.len() {
            if nums[i] + nums[j] == target {
                return Some((i, j));
            }
        }
    }
    None
}
