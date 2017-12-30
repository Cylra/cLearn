#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>

using namespace std;

const int PORT=8888;
const int BUFFSIZE = 2048;

bool sig_int = false;
void handel_sig(int)
{
    if(!sig_int){
        cout<<"发现ctrl-c信号"<<endl;
        sig_int = true;
    }
}

int getFileInfo(int s_c, string& fileName, int& fileSize)
{
    char buf[BUFFSIZE];
    read(s_c, buf, BUFFSIZE);
    write(s_c, "ok", 2);
    fileName = buf;
    cout <<"获取的文件名:" <<fileName << endl;
    read(s_c, buf, sizeof(int));
    write(s_c, "ok", 2);
    
    memcpy(&fileSize, buf, sizeof(int));
    cout << fileSize <<endl;
    return 0;
}

void *(thread_client)(void *arg)  
{
    int s_c = *(int*)arg;
    //read,write
    int n_readOnce;
    char buf[BUFFSIZE];

    string fileName;
    int fileSize;
    getFileInfo(s_c, fileName, fileSize);
    
    //文件写入
    FILE *fp = fopen(fileName.c_str(), "wb");
    n_readOnce = read(s_c, buf, BUFFSIZE);
    write(s_c, "ok", 2);
    int sum = 0;
    while(n_readOnce > 0)
    {
        sum += n_readOnce;
        fwrite(buf, 1, n_readOnce, fp);
        n_readOnce = read(s_c, buf, BUFFSIZE);
        write(s_c, "ok", 2);
        cout << "已接收: " << sum/(fileSize+0.0)*100 <<"%"<< endl;
    }
    cout << sum << "字节已接收" << endl;
    
    fclose(fp);
    cout<<"客户端退出:" << s_c << endl;
    close(s_c);
}  

int main()
{
    int s_s = socket(AF_INET, SOCK_STREAM, 0);
    if(s_s < 0)
        return -1;
    sockaddr_in st1;
    memset(&st1, 0, sizeof(st1));
    st1.sin_family = AF_INET;
    st1.sin_port   = htons(PORT);
    st1.sin_addr.s_addr = INADDR_ANY;
    bind(s_s, (const sockaddr*)&st1, sizeof(sockaddr_in));
    listen(s_s, 5);
    signal(SIGINT,&handel_sig);
    cout<<s_s<<endl;
    
    while(!sig_int){
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(s_s, &readSet);
        timeval timeout;
        timeout.tv_sec  = 1;
        timeout.tv_usec = 0;

        int result = select(s_s + 1, &readSet, NULL, NULL, &timeout);
        pthread_t t1;
        if(result > 0)
        {
            //先处理客户端的msg,再接入新的连接
            if(FD_ISSET(s_s, &readSet))
            {
                sockaddr_in client;
                int client_len = sizeof(sockaddr_in);
                memset(&client, 0, sizeof(client));
                int s_c = accept(s_s, (sockaddr*)&client, (socklen_t *)&client_len);
                if(s_c < 0){
                    break;
                }
                cout<<"有客户端接入:" << s_c << endl;
                int ret = pthread_create(&t1 ,NULL,(void* (*)(void*))&thread_client,(void *)&s_c); 
                pthread_join(t1, NULL);
            }
        }
    }
    close(s_s);
    return 0;
}