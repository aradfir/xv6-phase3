#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    changePolicy(1);
    int pid = fork();
    if (pid < 0){
        printf(1,"fork error\n");
        return 0;
    }
    printf(1,"fork 1 completed\n");
    for (int i=0 ; i<9 ; i++) {
        if (pid != 0) {
            pid = fork();
            if (pid < 0){
                printf(1,"fork error\n");
                exit();
            }
            printf(1,"fork %d completed\n",i+2);
        } else {
            break;
        }
    }
    if (pid == 0){
        pid = getpid();
        for (int j=1 ; j<1000 ; j++) {
            printf(1,"%d : %d\n" , pid , j);
        }
        int turnaroundTime = getTurnaroundTime();
        int waitingTime = getWaitingTime();
        int cbt = getCBT();
        sleep(1000+20*pid);
        printf(1,"Turnaround time of %d : %d\n" , pid , turnaroundTime);
        printf(1,"Waiting time of %d : %d\n" , pid , waitingTime);
        printf(1,"CBT of %d : %d\n" , pid , cbt);
        exit();
    } else {
        for (int i=0 ; i<10 ; i++) {
            wait();
            printf(1,"Wait %d is finished\n",i);
        }
    }
    exit();
}