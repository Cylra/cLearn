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
const int BUFFSIZE = 2048;

int getSize(string file)
{
    FILE *fp = fopen(file.c_str(),"rb");
    int sum = 0;
    char buf[128];
    int n;
    do{
        n = fread(buf, 1, 128, fp);
        sum += n;
    }while(n>0);
    fclose(fp);
    return sum;
}

int sendFileInfo(int s_c, string fileName, int& fileSize)
{
    fileSize = getSize(fileName);
    char buf[BUFFSIZE];
    memset(buf, 0, BUFFSIZE);

    int len = strlen(fileName.c_str());
    memcpy(buf, fileName.c_str(), len);
    write(s_c, buf, len);
    read(s_c, buf, BUFFSIZE);
    memcpy(buf, &(fileSize), sizeof(int));
    cout << "文件大小:" << fileSize << endl;
    write(s_c, buf, sizeof(int));
    return 0;
}

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
    st1.sin_addr.s_addr = inet_addr("127.0.0.1");
    int ret = connect(s_c, (const struct sockaddr *)&st1, sizeof(sockaddr_in));
    if(ret < 0){
        close(s_c);
        cout<<"连接服务器失败"<<endl;
        return -1;
    }

    string fileName = argv[1];
    int fileSize;
    sendFileInfo(s_c, fileName, fileSize);

    //读文件
    char buf[BUFFSIZE];
    FILE *fp = fopen(fileName.c_str(), "rb");
    int n_writeOnce = fread(buf, 1, BUFFSIZE, fp);
    int sum = 0;
    while(n_writeOnce) 
    {
        int success = write(s_c, buf, n_writeOnce);
        read(s_c, buf, 3);
        //cout << "已经发送" << sum/(fileSize+0.0)*100 <<"%"<< endl;
        sum += success;
        n_writeOnce = fread(buf, 1, BUFFSIZE, fp);     
    }
    cout << sum <<"字节已发送" <<endl;

    fclose(fp);
    close(s_c);
    return 0;
}