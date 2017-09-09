#include <linux/cdrom.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("/dev/cdrom", O_RDONLY|O_NONBLOCK);
    if(-1 == fd){
        printf("打开CDROM失败\n");
        return -1;
    }
    //向Linux内核的CDROM驱动程序发送CDROMEJECT请求
    if(!ioctl(fd, CDROMEJECT, NULL)){
        printf("成功弹出CDROM\n");
    }
    else{
        printf("弹出CDROM失败\n");
    }
    
    close(fd);
    return 0;
}