// sum pair of numbers in array
fn sum_pairs_in_list(list: Vec<i32>) -> i32 {
    // base case
    if list.len() == 2 {
        return list[0] + list[1];
    }
    return list[0] + list[1] + sum_pairs_in_list(list[1..].to_vec());
}

// base case: fn([2, 2]) = 4
#[test]
fn test_sum_pars_in_list_2_values() {
    let result: Vec<i32> = vec![2, 2];
    assert_eq!(4, sum_pairs_in_list(result));
}

/*
    general case 1: fn([2, 2, 4, 5]) =  4 + 6 + 9
    general case 1: fn([2, 2, 4]) =  4 + 6

    ...

    general case 1 = 9 + fn([2, 2, 4]) = 9 + fn([6, fn([2, 2])])

*/
#[test]
fn test_sum_pars_in_list_4_values() {
    let result: Vec<i32> = vec![2, 2, 4, 5];
    assert_eq!(19, sum_pairs_in_list(result));
}

#[test]
fn test_sum_pars_in_list_8_values() {
    let result: Vec<i32> = vec![2, 2, 4, 5, 6, 7, 8, 9];
    assert_eq!(75, sum_pairs_in_list(result));
}
