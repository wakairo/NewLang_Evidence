fn choose_volume(stock: usize, flag: bool) -> usize {
    if (flag) {
        stock / usize(7)
    } else {
        stock / usize(5)
    }
}

fn main() -> unit {
    let limit = usize(100);
    let first_flag = usize(64) < limit;
    let second_flag = usize(124) < limit;
    let first_stock = if (first_flag) {
        usize(97)
    } else {
        usize(54)
    };
    let first = choose_volume(first_stock, first_flag);
    let second_stock = if (second_flag) {
        usize(97)
    } else {
        usize(54)
    };
    let second = choose_volume(second_stock, second_flag);
    unit
}
