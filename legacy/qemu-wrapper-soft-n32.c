#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
    char *newargv[argc + 3];

    newargv[0] = argv[0];
    newargv[1] = "-L";
    newargv[2] = "/usr/mips64el-softfloat-linux-gnuabin32";

    memcpy(&newargv[3], &argv[1], sizeof(*argv) * (argc - 1));
    newargv[argc + 2] = NULL;
    return execve("/usr/bin/qemu-mipsn32el", newargv, envp);
}
