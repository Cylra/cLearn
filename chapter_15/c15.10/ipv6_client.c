#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <resolv.h>

#define BUF_LEN 1024
#define MYPORT 8888
#define BACKLOG 10

int main(int argc, char **argv)
{
    int s_c;
    int len;
    int err = -1;
    struct sockaddr_in6 server_addr;
    char buf[BUF_LEN + 1];

    s_c = socket(PF_INET6, SOCK_STREAM, 0);
    if(-1 == s_c){
        perror("socket error");
        return 1;
    }
    else{
        printf("socket() success\n");
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin6_family = PF_INET6;
    server_addr.sin6_port = htons(MYPORT);   //端口
    server_addr.sin6_addr = in6addr_any;    //IPv6任意地址
    //连接服务器
    err = connect(s_c, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in6));
    if(-1 == err){
        perror("connect error");
        return 1;  
    }
    else{
        printf("connect() success\n");
    }

    bzero(buf, BUF_LEN + 1);
    //接收服务器数据,打印信息
    len = recv(s_c, buf, BUF_LEN, 0);
    printf("Received %d bytes: %s\n", len, buf);
    bzero(buf, BUF_LEN + 1);
    //向服务器发送数据
    strcpy(buf, "From Client");
    len = send(s_c, buf, strlen(buf), 0);

    close(s_c); //关闭套接字
    return 0;
}