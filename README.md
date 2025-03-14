Wrapper for QEMU user chroot
===

Legacy C code are originally copied from [Compiling with QEMU user chroot](https://wiki.gentoo.org/wiki/Embedded_Handbook/General/Compiling_with_QEMU_user_chroot).

- qemu-wrapper-${ABI}: `qemu-mips*el -cpu Loongson-2F`
- qemu-wrapper-hard-\${ABI}: `qemu-mips*el -L /usr/mips64el-unknown-linux-gnuabi${ABI}`
- qmeu-wrapper-hard-loongson-\${ABI}: `qemu-mips*el -cpu Loongson-2F -L /usr/mips64el-unknown-linux-gnuabi${ABI}`

The first one is used with chroot, as shown in [chroot-mips64el](scripts/chroot-mips64el).

The middle two are used for cross-compiling.

Remember to configure binfmt before cross-compiling:

```bash
echo ':qemu-mips64el:M::\x7fELF\x02\x01\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x08\x00:\xff\xff\xff\xff\xff\xff\xff\x00\x00\xff\xff\xff\xff\xff\xff\xff\xfe\xff\xff\xff:/usr/local/bin/qemu-wrapper-hard-n64:OC' > /proc/sys/fs/binfmt_misc/register
```

The last two are used to run binary file directly to simulate command running on Lemote Yeeloong Netbook.

