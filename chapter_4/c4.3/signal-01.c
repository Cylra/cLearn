#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);
static void sig_handle(int signo)
{
    if(SIGSTOP == signo){
        printf("接收到信号: SIGSTOP\n");
    }
    else if(SIGKILL == signo){
        printf("接收到信号: SIGKILL\n");
    }
    else{
        printf("接收到信号: %d\n", signo);
    }
    return;
}

int main(void)
{
    //SIGSTOP和SIGKILL无法设置函数进行信号处理
    sighandler_t ret;
    ret = signal(SIGSTOP, sig_handle);
    if(SIG_ERR == ret){
        printf("为SIGSTOP挂接信号处理函数失败\n");
        //return -1;
    }
    ret = signal(SIGKILL, sig_handle);
    if(SIG_ERR == ret){
        printf("为SIGKILL挂接信号处理函数失败\n");
        //return -1;
    }
    signal(SIGINT, sig_handle);
    for(;;);
 }