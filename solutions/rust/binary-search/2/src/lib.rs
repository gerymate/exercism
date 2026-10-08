pub fn find<T, C>(array: C, key: T) -> Option<usize>
    where 
        C: AsRef<[T]>,
        T: PartialOrd + PartialEq,
    {
    let array = array.as_ref();
    let mut begin:usize = 0;
    let mut end:usize = array.len();
    while begin < end {
        let pivot = (begin + end) / 2;
        if array[pivot] == key {
            return Some(pivot);
        } else if array[pivot] < key {
            begin = pivot + 1;
        } else {
            end = pivot;
        }
    }
    None
}
