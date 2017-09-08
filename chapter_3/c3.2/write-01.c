#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd = -1;
    ssize_t size = -1;
    char buf[] = "quick brown fox jumps over the lazy dog";
    char filename[] = "test.txt";
    fd = open(filename, O_RDWR);
    if(-1 == fd){
        printf("Open file %s failure, fd:%d\n", filename, fd);
        exit(-1);
    }
    else{
        printf("Open file %s success, fd:%d\n", filename, fd);
    }
    size = write(fd, buf, strlen(buf));
    printf("write %d byted to file %s\n", size, filename);
    
    close(fd);
    return 0;
}