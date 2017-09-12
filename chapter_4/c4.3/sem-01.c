/*信号量,需要sudo权限
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

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
    int semid;
    int i, value = 0;
    
    key = ftok("/ipc/sem/", 'a');
    semid = CreateSem(key, 100); //建立信号量
    for(i=0; i<=3; i++){
        Sem_P(semid);
        printf("信号量的值为: %d\n", GetvalueSem(semid));
        Sem_V(semid);
        printf("信号量的值为: %d\n", GetvalueSem(semid));
    }
    value = GetvalueSem(semid);
    printf("信号量的值为: %d\n", value);

    DestroySem(semid);
    return 0;
}