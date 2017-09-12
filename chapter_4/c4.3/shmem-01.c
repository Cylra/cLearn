/*需要sudo权限
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

static char msg[] = "你好,共享内存\n";

typedef int sem_t;
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
} arg;

sem_t CreateSem(key_t key, int value)
{
    union semun sem;
    sem_t semid;
    sem.val = value;

    semid = semget(key, 1, IPC_CREAT|0666);
    if(-1 == semid){
        printf("创建信号量出错\n");
        return -1;
    }

    semctl(semid, 0, SETVAL, sem);
    return semid;
}

int Sem_P(sem_t semid){
    struct sembuf sops = {0, +1, IPC_NOWAIT};
    return (semop(semid, &sops, 1));
}

int Sem_V(sem_t semid){
    struct sembuf sops = {0, -1, IPC_NOWAIT};
    return (semop(semid, &sops, 1));
}

void SetvalueSem(sem_t semid, int value)
{
    union semun sem;
    sem.val = value;
    semctl(semid, 0, SETVAL, sem);
}

int GetvalueSem(sem_t semid)
{
    union semun sem;
    return semctl(semid, 0, GETVAL, sem);
}

void DestroySem(sem_t semid)
{
    union semun sem;
    sem.val = 0;
    semctl(semid, 0, IPC_RMID, sem);
}

//主函数
int main(void)
{
    key_t key;
    int semid, shmid;
    char i, *shms, *shmc;
    struct semid_ds buf;
    int value = 0;
    char buffer[80];
    pid_t p;

    key = ftok("/ipc/sem", 'a');
    shmid = shmget(key, 1024, IPC_CREAT|0604); //生成共享内存,大小1024个字节
    semid = CreateSem(key, 0);   //建立信号量

    p = fork();
    if(p > 0){  //父进程
        shms = (char *)shmat(shmid, 0, 0);
        memcpy(shms, msg, strlen(msg) + 1);
        sleep(10);
        Sem_P(semid);

        shmdt(shms);  //移除共享内存
        DestroySem(semid);//销毁信号量
    }
    else if(0 == p){ //子进程
        shmc = (char *)shmat(shmid, 0, 0);
        Sem_V(semid);
        printf("共享内存的值为: %s\n", shmc);
        
        shmdt(shmc);
    }
    return 0;
}