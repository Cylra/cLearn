/*实现字符串IP地址(eg: 255.255.255.0)和
二进制整数(eg: 0xffffff00)IP地址的转换
*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char** argv)
{
    char *local = "127.0.0.1";
    struct in_addr addr1, addr4;
    in_addr_t addr2, addr3;
    char *c;

    //地址字符串转整数
    int i = inet_aton(local, &addr1);
    printf("addr1.s_addr = %#x\n", addr1.s_addr);

    /*inet_addr是inet_aton的缩减版,
      参数非法会返回-1，-1同时是255.255.255.255的转换结果
      所以不能使用此函数转换IP地址:"255.255.255.255"
    */
    addr2 = inet_addr(local);
    printf("addr2 = %#x\n", addr2);

    addr3 = inet_network(local);
    printf("addr3 = %#x\n", addr3);

    //数字转字符串
    addr4.s_addr = 0x7f000001;
    c = inet_ntoa(addr4);
    printf("str: %s\n", c);

    unsigned long net, host;
    net = 0x0000007F;
    host = 0x00000001;
    struct in_addr addr5 = inet_makeaddr(net, host);
    printf("addr5.s_addr = %#x\n", addr5.s_addr);

    struct in_addr ip;
    ip.s_addr = inet_network(local);
    in_addr_t host_id = inet_lnaof(ip);
    printf("主机号: %x\n", host_id);

    ip.s_addr = inet_network(local);
    in_addr_t net_id = inet_netof(ip);
    printf("网络号: %x\n", net_id);

    //能处理IPv6地址的转换函数
    struct in_addr addr6;
    int j = inet_pton(AF_INET, local, (void *)&addr6);
    printf("addr6.s_addr = %#x\n", addr6.s_addr);

    char buf[130];
    const char *c2 = inet_ntop(AF_INET, &addr6, buf, 130);
    printf("str2: %s\n", buf);
    return 0;
}