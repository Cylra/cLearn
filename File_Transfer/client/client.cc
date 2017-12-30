#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

const int PORT=8888;
struct FileStat
{
    string filename;
    bool   isBin;
};

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << argv[0] << " filePath"<<endl;
        return -1;
    }
    int s_c = socket(AF_INET, SOCK_STREAM, 0);
    if(s_c < 0)
        return -1;
    sockaddr_in st1;
    memset(&st1, 0, sizeof(st1));
    st1.sin_family = AF_INET;
    st1.sin_port   = htons(PORT);
    st1.sin_addr.s_addr = inet_addr("192.168.2.126");
    int ret = connect(s_c, (const struct sockaddr *)&st1, sizeof(sockaddr_in));
    if(ret < 0){
        close(s_c);
        cout<<"连接服务器失败"<<endl;
        return -1;
    }

    FileStat ft1;
    string src_path(argv[1]);
    if(src_path[0] != '/')
    {
        src_path = "./" + src_path;
    }
    ft1.filename = src_path;
    cout<< "路径是:" << ft1.filename << endl;

    //读文件
    int fd1 = open(src_path.c_str(), O_RDONLY);
    char buf[2048];
    int n_writeOnce;
    n_writeOnce = read(fd1, buf, 2048);
    
    while(n_writeOnce) 
    {
        write(s_c, buf, n_writeOnce);
        n_writeOnce = read(fd1, buf, 2048);
    }

    close(fd1);
    close(s_c);
    return 0;
}