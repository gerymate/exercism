#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}
use crate::Comparison::*;

pub fn sublist<T: PartialEq>(first_list: &[T], second_list: &[T]) -> Comparison {
    match true {
        _ if first_list == second_list => Equal,
        _ if is_sublist(first_list, second_list) => Sublist,
        _ if is_sublist(second_list, first_list) => Superlist,
        _ => Unequal
    }
}

fn is_sublist<T: PartialEq>(first_list: &[T], second_list: &[T]) -> bool {
    let first_len = first_list.len();
    let second_len = second_list.len();
    if first_len > second_len {
        return false
    }
    for i in 0 ..= second_len-first_len {
        if &second_list[i .. i+first_len] == first_list {
            return true
        }
    }
    false
}
