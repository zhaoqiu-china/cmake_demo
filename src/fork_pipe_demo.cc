#include <unistd.h>
#include <cstdio>

int main()
{
    
    int pipefd[2];
    pipe(pipefd);
    pid_t p = fork();
    int a = 12;
    int b = 13;
    if (p < 0)
    {
        return -1;
    }
    else if (p == 0)
    {
        // child process
        std::printf("child process\n");
        write(pipefd[1], &a, sizeof(int));
    }
    else
    {
        std::printf("main process\n");
        read(pipefd[0], &b, sizeof(int));
        std::printf("b: %d\n", b);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    
    return 0;
}