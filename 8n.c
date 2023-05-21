#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void main()
{
    int child,shmid,i;
    char *shmptr;
    child=fork();
    if(!child)
    {
        shmid=shmget(2041,32,0666|IPC_CREAT);
        shmptr=shmat(shmid,0,0);
        printf("\nparent writing\n")
        for(i=0;i<10;i++)
        {
            shmptr[i]='a'+i;
            putchar(shmptr[i]);
        }
        printf("\n\n%s",shmptr);
        wait(NULL);
    }
    else
    {
        shmid=shmget(2014,32,0666);
        shmptr=shmat(shmid,0,0);
        printf("\nchild is reading\n")
        for(i=0;i<10;i++)
            putchar(shmptr[i]);
        shmdt(NULL);
    }
}
