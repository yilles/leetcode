use std::collections::HashMap;

pub fn two_sum(nums: &Vec<i32>, target: i32) -> Option<(usize, usize)> {
    let mut map = HashMap::new();
    for i in 0..nums.len() {
        let complement = target - nums[i];
        match map.get(&complement) {
            Some(&j) => return Some((j, i)),
            None => (),
        }
        map.insert(nums[i], i);
    }
    None
}
