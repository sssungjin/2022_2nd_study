#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int fib(int n)

{

    pid_t pid, child;
    int status;
    int fib_n_1 = 0, fib_n_2 = 0;

    if (n <= 2)
        return (1);
    pid = fork();

    if (pid > 0)
    {
        child = wait(&status);
        fib_n_1 = WEXITSTATUS(status); //반환 값 fib_n_1 저장
        fib_n_2 = fib(n - 2);
    }
    else if (pid == 0)
    {
	    fib_n_1 = fib(n-1);
	    exit(fib_n_1);
    }
    else
        printf("fork error");
    return (fib_n_1 + fib_n_2);
}

int main()

{

    int n;
    scanf("%d", &n);
    int result = fib(n);

    printf("fibo(%d) = %d\n", n, result);
    return 0;
}
