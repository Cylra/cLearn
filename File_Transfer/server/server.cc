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

using namespace std;

const int PORT=8888;

bool sig_int = false;
void handel_sig(int)
{
    if(!sig_int){
        cout<<"发现ctrl-c信号"<<endl;
        sig_int = true;
    }
}

void *(thread_client)(void *arg)  
{
    int s_c = *(int*)arg;
    //read,write
    cout<<"进入线程获取到参数:" <<s_c <<endl;
    int n_readOnce;
    char buf[2048];
    int fd1 = open("testServerFile", O_WRONLY|O_CREAT|O_TRUNC);

    n_readOnce = read(s_c, buf, 2048);
    while(n_readOnce > 0)
    {
        write(fd1, buf, n_readOnce);
        cout << "从客户端接收到:" <<endl;
        cout << buf;
        n_readOnce = read(s_c, buf, 2048);
    }

    close(fd1);
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