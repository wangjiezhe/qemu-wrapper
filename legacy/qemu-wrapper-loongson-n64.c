#include <string.h>
#include <unistd.h>

int main(int argc, char** argv, char** envp) {
    char* newargv[argc + 7];

    newargv[0] = argv[0];
    newargv[1] = "-cpu";
    newargv[2] = "Loongson-2F";
    newargv[3] = "-L";
    newargv[4] = "/usr/mips64el-unknown-linux-gnuabi64";
    newargv[5] = "-E";
    newargv[6] =
        "LD_LIBRARY_PATH=/usr/lib/gcc/mips64el-unknown-linux-gnuabi64/14/";

    memcpy(&newargv[7], &argv[1], sizeof(*argv) * (argc - 1));
    newargv[argc + 6] = NULL;
    return execve("/usr/bin/qemu-mips64el", newargv, envp);
}
