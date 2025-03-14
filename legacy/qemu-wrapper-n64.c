#include <string.h>
#include <unistd.h>

int main(int argc, char** argv, char** envp) {
    char* newargv[argc + 5];

    newargv[0] = argv[0];
    newargv[1] = "-L";
    newargv[2] = "/usr/mips64el-unknown-linux-gnuabi64";
    newargv[3] = "-E";
    newargv[4] =
        "LD_LIBRARY_PATH=/usr/lib/gcc/mips64el-unknown-linux-gnuabi64/14/";

    memcpy(&newargv[5], &argv[1], sizeof(*argv) * (argc - 1));
    newargv[argc + 4] = NULL;
    return execve("/usr/bin/qemu-mips64el", newargv, envp);
}
