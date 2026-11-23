fn choose_quota(stock: usize, flag: bool) -> usize {
    if (flag) {
        stock / usize(6)
    } else {
        stock / usize(8)
    }
}

fn main() -> unit {
    let stock = usize(95);
    let limit = usize(103);
    let above_first = usize(80) < limit;
    let above_second = usize(120) < limit;
    let first = choose_quota(stock, above_first);
    let second = choose_quota(stock, above_second);
    unit
}
