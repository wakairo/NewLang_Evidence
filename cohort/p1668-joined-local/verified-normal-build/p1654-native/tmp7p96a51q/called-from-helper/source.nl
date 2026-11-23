fn choose(flag: bool) -> usize {
    let amount = if (flag) {
        usize(11)
    } else {
        usize(19)
    };
    amount
}

fn relay(flag: bool) -> usize { choose(flag) }

fn main() -> unit {
    let stock = usize(77);
    let select_first = usize(50) < stock;
    let select_second = usize(90) < stock;
    let first = relay(select_first);
    let second = choose(select_second);
    unit
}
