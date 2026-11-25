struct ReceiveSetting { route_tag: u8, mode: u8 }

fn main() -> unit {
    let active = ReceiveSetting{mode: u8(41), route_tag: u8(117)};
    let escaped = loan_write(active@mode) { |field| field };
    return unit;
}
