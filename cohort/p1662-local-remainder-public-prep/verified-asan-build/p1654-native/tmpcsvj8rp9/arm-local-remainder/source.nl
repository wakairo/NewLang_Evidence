fn choose_remainder(flag: bool) -> usize {
    if (flag) {
        let stock = usize(83);
        stock % usize(7)
    } else {
        let stock = usize(83);
        stock % usize(5)
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
