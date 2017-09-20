/*实现域名(www.baidu.com)与IP地址之间的转换,
socket的API均基于IP地址
*/
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char** argv)
{
    struct hostent *host1 = gethostbyname("www.baidu.com");
    int i =0;
    char **p;
    char buf[130];
    if(host1){
        printf("获取host: www.baidu.com 的信息\n");
        printf("官方名称: %s\n", host1->h_name);
        p = host1->h_aliases;
        while(*p){
            printf("主机别名: %s\n", *p);
            p++;
        }
        //地址可能是IPv4或IPv6
        printf("主机的地址类型: %s\n", host1->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");
        printf("主机的IP地址长度: %d个字节\n", host1->h_length);
        p = host1->h_addr_list;
        while(*p){
            //在计算机和网络上的IP地址为二进制,使用ntop转换为字符串
            printf("主机的IP地址: %s\n", inet_ntop(host1->h_addrtype, *p, buf, 130));
            p++;
        }
    }

    struct in_addr ip;
    inet_pton(AF_INET, "223.5.5.5", &ip);
    struct hostent *host2 = gethostbyaddr(&ip, sizeof(struct in_addr), AF_INET);
    printf("%s\n", host2 == NULL ? "True" : "False");
    /*gethostby...()函数分配错误代码h_errno而不是errno
      使用hstrerror()而不是strerror()报告错误消息
    */
    printf("h_errno = %d, str = %s\n", h_errno, hstrerror(h_errno));
    if(host2){
        printf("获取host: 14.215.177.38 的信息\n");
        printf("官方名称: %s\n", host2->h_name);
        p = host2->h_aliases;
        while(*p){
            printf("主机别名: %s\n", *p);
            p++;
        }
        //地址可能是IPv4或IPv6
        printf("主机的地址类型: %s\n", host2->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");
        printf("主机的IP地址长度: %d个字节\n", host2->h_length);
        p = host2->h_addr_list;
        while(*p){
            //在计算机和网络上的IP地址为二进制,使用ntop转换为字符串
            printf("主机的IP地址: %s\n", inet_ntop(host2->h_addrtype, *p, buf, 130));
            p++;
        }

    }
    return 0;
}