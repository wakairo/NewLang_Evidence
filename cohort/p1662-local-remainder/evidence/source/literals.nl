fn choose_remainder(flag: bool) -> usize {
    if (flag) {
        usize(6)
    } else {
        usize(3)
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
