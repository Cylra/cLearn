#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i = 0;
    int fd = 0;
    for(i=0; fd>=0; i++)
    {
        fd = open("test.txt", O_RDONLY);
        if(fd > 0){
            printf("fd:%d\n", fd);
            close(fd);
        }
        else{
            printf("error, can't open file\n");
            exit(0);
        }
    }
    return 0;
}