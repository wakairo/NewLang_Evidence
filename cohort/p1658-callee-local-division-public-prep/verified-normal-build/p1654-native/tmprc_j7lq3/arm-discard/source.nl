fn select_mark(flag: bool) -> usize {
    if (flag) {
        usize(23)
    } else {
        usize(41)
    }
}

fn main() -> unit {
    let stock = usize(61);
    let first_flag = usize(30) < stock;
    let second_flag = usize(70) < stock;
    let guarded = if (first_flag) {
        select_mark(first_flag);
        usize(7)
    } else {
        usize(9)
    };
    select_mark(second_flag);
    unit
}
