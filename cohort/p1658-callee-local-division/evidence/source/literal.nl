fn choose_quota(flag: bool) -> usize {
    if (flag) {
        usize(15)
    } else {
        usize(11)
    }
}

fn main() -> unit {
    let limit = usize(103);
    let above_first = usize(80) < limit;
    let above_second = usize(120) < limit;
    let first = choose_quota(above_first);
    let second = choose_quota(above_second);
    unit
}
