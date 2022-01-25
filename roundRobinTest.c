#include "types.h"
#include "user.h"
#include "stat.h"



int main(void)
{
    changePolicy(1);
    int pid = fork();
    for (int i=0 ; i<9 ; i++) {
        if (pid == 0) {
            pid = fork();
        } else {
            break;
        }
    }
    if (pid != 0){
        int turnAroundTime = 0;
        int waitingTime = 0;
        int cbt = 0;
        for (int j=1 ; j<1001 ; j++) {
            printf(1,"%d : %d\n", pid, j);
        }
        printf(1,"Turn around time of %d : %d\n", pid, turnAroundTime);
        printf(1,"Waiting time of %d : %d\n", pid, waitingTime);
        printf(1,"CBT of %d : %d\n", pid, cbt);
    }
    exit();
}