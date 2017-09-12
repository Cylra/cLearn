#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    //产生子进程
    pid = fork();
    if(-1 == pid){
        printf("进程创建失败!\n");
        return -1;
    }
    else if(0 == pid){
        printf("子进程,fork返回值: %d, 进程ID: %d, 父进程ID: %d\n", pid, getpid(), getppid());
    }
    else{
        printf("父进程,fork返回值: %d, 进程ID: %d, 父进程ID: %d\n", pid, getpid(), getppid());
    }
    
    return 0;
}