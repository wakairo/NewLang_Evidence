fn choose(flag: bool) -> usize {
    let stock = usize(77);
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
    let first = choose(select_first);
    let second = choose(select_second);
    unit
}
