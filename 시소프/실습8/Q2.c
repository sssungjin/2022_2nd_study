#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;
    pid = fork();

    putenv("APPLE=RED");
    if(pid > 0) {
        printf("[parent] PID : %d\n", getpid());
        printf("[parent] PPID : %d\n", getppid());
        printf("[parent] GID : %d\n", getpgrp());
        printf("[parent] SID : %d\n", getsid(0));
        waitpid(pid, &status, 0);
        printf("[parent] status is : %d\n", status);
        unsetenv("APPLE");
    }
    else if(pid == 0) {
        printf("[child] PID : %d\n", getpid());
        printf("[child] PPID : %d\n", getppid());
        printf("[child] GID : %d\n", getpgid());
        printf("[child] SID : %d\n", getsid());
        sleep(1);
        printf("[child] APPLE=%s\n", getenv("APPLE"));
        exit(1);
    }
    else
        printf("fail to fork\n");
    return 0;
}