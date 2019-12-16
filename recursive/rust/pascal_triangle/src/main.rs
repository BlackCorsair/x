fn main() {
    let triangle = pascal_triangle(10);
    let tabs = triangle.len();
    for index in 0..triangle.len() {
        for _ in 0..((tabs - index)) {
            print!("  ");
        }
        println!("{:?}", triangle[index]);
    }
}

// https://en.wikipedia.org/wiki/Pascal%27s_triangle
fn pascal_triangle(depth: i32) -> Vec<Vec<i32>> {
    if depth == 1 {
        return vec![vec![1]];
    }
    if depth == 2 {
        return vec![vec![1], vec![1, 1]];
    }
    let mut triangle: Vec<Vec<i32>> = Vec::new();
    triangle.extend(pascal_triangle(depth - 1));

    let mut row: Vec<i32> = Vec::new();
    row.push(1);
    row.extend(sum_pairs_in_list(
        pascal_triangle(depth - 1).last().clone().unwrap().to_vec(),
    ));
    row.push(1);
    triangle.push(row);

    return triangle;
}

// pascal_triangle base case 1
// fn(1) = [[1]]
#[test]
fn test_pascal_triangle_base_case_len_1() {
    let result: Vec<Vec<i32>> = pascal_triangle(1);
    let expected: Vec<Vec<i32>> = vec![vec![1]];

    assert_eq!(expected, result);
}

// pascal_triangle base case 2
// fn(2) = [[1], [1, 1]]
// fn(2) = [fn(1), fn(2)]
#[test]
fn test_pascal_triangle_base_case_len_2() {
    let result: Vec<Vec<i32>> = pascal_triangle(2);
    let expected: Vec<Vec<i32>> = vec![vec![1], vec![1, 1]];

    assert_eq!(expected, result);
}

/* pascal_triangle general case 5
fn(5): [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1],
        [1, 4, 6, 4, 1]]
        ==
fn(5): [fn(1),
        fn(2),
        [1, 2, 1],
        [1, 3, 3, 1],
        [1, 4, 6, 4, 1]]


                    1
                1       1
            1       2       1
        1       3       3       1
    1       4       6       4       1
*/

#[test]
fn test_pascal_triangle_general_case_len_5() {
    let result: Vec<Vec<i32>> = pascal_triangle(5);
    let expected: Vec<Vec<i32>> = vec![
        vec![1],
        vec![1, 1],
        vec![1, 2, 1],
        vec![1, 3, 3, 1],
        vec![1, 4, 6, 4, 1],
    ];

    assert_eq!(expected, result);
}

/* pascal_triangle general case 3
fn(3): [[1], [1, 1], [1, 2, 1]]
        ==
fn(3): [fn(1),
        fn(2),
        [1, 2, 1]]
fn(3): [fn(1),
        fn(2),
        [1, sum_pairs_in_list(fn(2)), 1]]


                    1
                1       1
            1       2       1
*/

#[test]
fn test_pascal_triangle_general_case_len_3() {
    let result: Vec<Vec<i32>> = pascal_triangle(3);
    let expected: Vec<Vec<i32>> = vec![vec![1], vec![1, 1], vec![1, 2, 1]];

    assert_eq!(expected, result);
}

// sum pair of numbers in array
fn sum_pairs_in_list(list: Vec<i32>) -> Vec<i32> {
    // base case
    if list.len() == 2 {
        return vec![list[0] + list[1]];
    }
    let mut sum: Vec<i32> = Vec::new();
    sum.push(list[0] + list[1]);
    sum.extend(sum_pairs_in_list(list[1..].to_vec()));
    return sum;
}

// base case: fn([2, 2]) = [4]
#[test]
fn test_sum_pars_in_list_2_values() {
    let result: Vec<i32> = vec![2, 2];
    assert_eq!(vec![4], sum_pairs_in_list(result));
}

/*
    general case 1: fn([2, 2, 4, 5]) =  [4 , 6 , 9]
    general case 1: fn([2, 2, 4]) =  [4 , 6]

    ...

    general case 1 = 9 , fn([2, 2, 4]) = [9 , fn([6, fn([2, 2])])]

*/
#[test]
fn test_sum_pars_in_list_4_values() {
    let result: Vec<i32> = vec![2, 2, 4, 5];
    assert_eq!(vec![4, 6, 9], sum_pairs_in_list(result));
}

#[test]
fn test_sum_pars_in_list_8_values() {
    let result: Vec<i32> = vec![2, 2, 4, 5, 6, 7, 8, 9];
    assert_eq!(vec![4, 6, 9, 11, 13, 15, 17], sum_pairs_in_list(result));
}
