fn choose_remainder(stock: usize, flag: bool) -> usize {
    if (flag) {
        stock % usize(7)
    } else {
        stock % usize(5)
    }
}

fn main() -> unit {
    let stock = usize(83);
    let limit = usize(100);
    let early = usize(61) < limit;
    let late = usize(123) < limit;
    let first = choose_remainder(stock, early);
    let second = choose_remainder(stock, late);
    unit
}
