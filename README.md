Wrapper for QEMU user chroot
===

Legacy c code are originally copied from [Compiling with QEMU user chroot](https://wiki.gentoo.org/wiki/Embedded_Handbook/General/Compiling_with_QEMU_user_chroot).

- qemu-wrapper-${ABI}: `qemu-mips*el -cpu Loongson-2F`, used for chroot
- qemu-wrapper-base-\${ABI}: `qemu-mips*el -L /usr/mips64el-unknown-linux-gnuabi${ABI}`
- qmeu-wrapper-loongson-\${ABI}: `qemu-mips*el -cpu Loongson-2F -L /usr/mips64el-unknown-linux-gnuabi${ABI}`

Last two command are used to run binary file directly.

