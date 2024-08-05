use std::env;
use std::process::Command;

fn main() {
    // Collect command line arguments, skipping the program name (args[0])
    let args: Vec<String> = env::args().skip(1).collect();

    let status = Command::new("/usr/bin/qemu-mips64el")
        .arg("-cpu")
        .arg("Loongson-2F")
        .args(args)
        .status()
        .expect("Failed to execute qemu-mips64el");

    if status.success() {
        println!("QEMU process completed successfully");
    } else {
        eprintln!("QEMU process failed");
        std::process::exit(1);
    }
}
