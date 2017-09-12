/*管道操作原子性的代码,
子进程一次写入128K字节的数据,
父进程每次读取10K字节的数据
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define K 1024
#define WRITELEN (128*K)

int main(void)
{
    int result = -1, nbytes;
    int fd[2];
    pid_t pid;
    char str1[WRITELEN] = "你好,管道";
    char readbuffer[10*K];

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
    if(0 == pid){   //子进程
        int write_size = WRITELEN;
        result = 0;
        close(*read_fd);  //关闭读端
        while(write_size > 0){
            result = write(*write_fd, str1, write_size);
            if(result > 0){
                write_size -= result;
                printf("写入%d个数据,剩余%d个数据\n", result, write_size);
            }
            else{
                sleep(10);
            }
        }
        //printf("子进程结束\n");
        return 0;
    }
    else{           //父进程
        close(*write_fd); //关闭写端

        while(1){
            nbytes = read(*read_fd, readbuffer, sizeof(readbuffer));
            if(nbytes <= 0){
                printf("没有数据写入了\n");
                break;
            }
            printf("接收到%d个数据,内容为: \"%s\"\n", nbytes, readbuffer);
        }
    }

    return 0;
}