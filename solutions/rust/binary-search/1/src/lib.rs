pub fn find<T, C>(array: C, key: T) -> Option<usize>
    where 
        C: AsRef<[T]>,
        T: PartialOrd + PartialEq,
    {
    let container = array.as_ref();
    let mut begin:usize = 0;
    let mut end:usize = container.len();
    while begin < end {
        let pivot = (begin + end) / 2;
        let value = &container[pivot];
        if *value == key {
            return Some(pivot);
        }
        if *value < key {
            begin = pivot + 1;
        } else {
            end = pivot;
        }
    }
    None
}
