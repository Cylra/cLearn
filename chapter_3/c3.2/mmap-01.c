#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

#define FILELENGTH 80

int main()
{
    int fd = -1;
    char buf[] = "quick brown fox jumps over the lazy dog";
    char *ptr  = NULL;
    
    /*打开文件mmap.txt,并将文件长度缩小为0,
     如果文件不存在则创建它,权限为可读写执行*/
    fd = open("mmap.txt",O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    if(-1 == fd){
        return -1;
    }
    /*将文件长度扩大为80,
    向后偏移文件的偏移量到79*/
    lseek(fd, FILELENGTH -1 , SEEK_SET);
    write(fd, "c", 1);//写入一个字符,文件长度此时80

    /*将文件mmap.txt中的数据从开头到80字节的数据映射到内存中,
    对文件的操作立刻显示在文件上,可读写*/
    ptr = (char*)mmap(NULL, FILELENGTH, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if((char*)-1 == ptr){
        printf("mmap failure\n");
        close(fd);
        return -1;
    }

    //将buf中的字符串复制到映射区域中,起始地址为ptr偏移16
    memcpy(ptr+16, buf , strlen(buf));
    munmap(ptr, FILELENGTH);
    close(fd);

    return 0;
}