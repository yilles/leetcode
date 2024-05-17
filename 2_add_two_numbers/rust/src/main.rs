mod submit1;

fn main() {
    let l1 = {2, 4, 3};
    let l2 = {5, 6, 4};
    let answer = submit1::add_two_numbers(l1, l2);
    printf("{}", answer);
}
