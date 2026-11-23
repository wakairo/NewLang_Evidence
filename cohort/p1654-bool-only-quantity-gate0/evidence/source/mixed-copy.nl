fn choose(stock: usize, flag: bool) -> usize {
    let amount = if (flag) {
        stock / usize(7)
    } else {
        stock / usize(4)
    };
    amount
}

fn main() -> unit {
    let stock = usize(77);
    let select_first = usize(50) < stock;
    let select_second = usize(90) < stock;
    let first = choose(stock, select_first);
    let second = choose(stock, select_second);
    unit
}
