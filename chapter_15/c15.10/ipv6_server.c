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

#define BUF_LEN 1024
#define MYPORT 8888
#define BACKLOG 10

int main(int argc, char **argv)
{
    int s_s, s_c;
    int len;
    int err = -1;

    struct sockaddr_in6 local_addr;
    struct sockaddr_in6 client_addr;
    char buf[BUF_LEN + 1];

    s_s = socket(PF_INET6, SOCK_STREAM, 0);
    if(-1 == s_s){
        perror("socket error");
        return 1;
    }
    else{
        printf("socket() success\n");
    }

    bzero(&local_addr, sizeof(local_addr));
    local_addr.sin6_family = PF_INET6;
    local_addr.sin6_port = htons(MYPORT);   //端口
    local_addr.sin6_addr = in6addr_any;    //IPv6任意地址
    err = bind(s_s, (struct sockaddr *)&local_addr, sizeof(struct sockaddr_in6));
    if(-1 == err){
        perror("bind error");
        return 1;  
    }
    else{
        printf("bind() success\n");
    }
    
    err = listen(s_s, BACKLOG);
    if(-1 == err){
        perror("listen error");
        return 1;  
    }
    else{
        printf("listen() success\n");
    }

    while(1){
        len = sizeof(struct sockaddr);
        //等待客户端连接
        s_c = accept(s_s, (struct sockaddr *)&client_addr, &len);
        if(-1 == s_c){
            perror("accept error");
            return(errno);  
        }
        else{
             //将客户端的地址转换成字符串
            inet_ntop(AF_INET6, &client_addr.sin6_addr, buf, sizeof(buf));
            printf("a client from ip: %s, 端口: %d, socket %d\n", \
            buf, \
            client_addr.sin6_port, \
            s_c);  //客户端套接字文件描述符
        }

        bzero(buf, BUF_LEN + 1);
        strcpy(buf, "From Server");
        len = send(s_c, buf, strlen(buf), 0);
        if(len < 0){
            printf("message '%s' send error, errno: %d, '%s'\n", \
                    buf, errno, strerror(errno));
        }
        else{
            printf("message '%s' send success, %d bytes\n", buf, len);
        }
        bzero(buf, BUF_LEN + 1);
        len = recv(s_c, buf, BUF_LEN, 0);
        if(len > 0){
            printf("recv message success: '%s', %d bytes\n", buf, len);
        }
        else{
            printf("recv message failure, errono: %d, '%s'\n", errno, strerror(errno));
        }
        //处理每个新连接上的数据收发结束
        close(s_c);
    }

    close(s_s);
    return 0;
}