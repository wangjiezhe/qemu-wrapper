#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
    char *newargv[argc + 5];

    newargv[0] = argv[0];
    newargv[1] = "-cpu";
    newargv[2] = "Loongson-2F";
    newargv[3] = "-L";
    newargv[4] = "/usr/mips64el-unknown-linux-gnuabin32";

    memcpy(&newargv[5], &argv[1], sizeof(*argv) * (argc - 1));
    newargv[argc + 4] = NULL;
    return execve("/usr/bin/qemu-mipsn32el", newargv, envp);
}
