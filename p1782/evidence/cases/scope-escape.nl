struct ReceiveDescriptor { class_tag: u8, coalescing: u8 }

fn main() -> unit {
    let active = ReceiveDescriptor{coalescing: u8(22), class_tag: u8(119)};
    let escaped = loan_write(active@coalescing) { |field| field };
    let old = replace(escaped, u8(35));
    return unit;
}
