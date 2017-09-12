/*在父进程与子进程之间建立一个管道,
子进程向管道中写入数据,父进程从管道中读取数据.
需要在父进程中关闭写(fd[1])
在子进程中关闭读(fd[0])
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int result = -1, nbytes;
    int fd[2];
    pid_t pid;
    char str1[] = "你好,管道\0";
    char readbuffer[80];

    //文件描述符1用于写,描述符0用于读
    int *write_fd = &fd[1];
    int *read_fd = &fd[0];

    result = pipe(fd);
    if(-1 == result){
        printf("建立管道失败\n");
        return -1;
    }
    pid = fork();
    if(-1 == pid){
        printf("进程创建失败\n");
        return -1;
    }
    if(0 == pid){
        close(*read_fd);  //关闭读端
        result = write(*write_fd, str1, strlen(str1));
        return 0;
    }
    else{           //父进程
        close(*write_fd); //关闭写端
        nbytes = read(*read_fd, readbuffer, sizeof(readbuffer));
        printf("接收到%d个数据,内容为: \"%s\"\n", nbytes, readbuffer);
    }

    return 0;
}