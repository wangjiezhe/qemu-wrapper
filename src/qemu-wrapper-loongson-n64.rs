use std::env;
use std::process::Command;

fn main() {
    // Collect command line arguments, skipping the program name (args[0])
    let args: Vec<String> = env::args().skip(1).collect();

    Command::new("/usr/bin/qemu-mips64el")
        .arg("-cpu")
        .arg("Loongson-2F")
        .arg("-L")
        .arg("/usr/mips64el-unknown-linux-gnuabi64")
        .args(args)
        .status()
        .expect("Failed to execute qemu-mips64el");
}
