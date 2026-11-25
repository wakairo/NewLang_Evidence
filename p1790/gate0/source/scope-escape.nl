struct QueueModes { reserve_mode: u8, normal_mode: u8 }

fn main() -> unit {
    let active = QueueModes{normal_mode: u8(41), reserve_mode: u8(117)};
    let outside = loan_write(active@normal_mode) { |slot| slot };
    let old = replace(outside, u8(35));
    return unit;
}
