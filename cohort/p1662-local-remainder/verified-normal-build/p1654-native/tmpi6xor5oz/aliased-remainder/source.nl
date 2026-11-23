fn choose_remainder(flag: bool) -> usize {
    let stock = usize(83);
    let alias = stock;
    if (flag) {
        alias % usize(7)
    } else {
        alias % usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let early = usize(61) < limit;
    let late = usize(123) < limit;
    let first = choose_remainder(early);
    let second = choose_remainder(late);
    unit
}
