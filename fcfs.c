//C Program to simulate the CPU Scheduling algorithm First Come First Serve

#include<stdlib.h>
#include<stdio.h>

struct Process {
    int burst, wait, turnAround;
}p[30] = {0};

int main() {
    int n, i, j, totalWaiting = 0, totalTurnAround = 0;
    printf("\nEnter number of processes : ");
    scanf("%d",&n);
    for(i = 0 ; i < n; i++) {
        printf("P[%d] : ", i + 1);
        scanf("%d",&p[i].burst);
    }
    p[0].wait = 0;
    for(i = 1; i < n; i++) {
        p[i].wait = 0;
        for(j = 0; j < i; j++) {
            p[i].wait += p[j].burst;
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnAround Time");
    for(i = 0; i < n; i++) {
        p[i].turnAround = p[i].burst + p[i].wait;
        totalWaiting += p[i].wait;
        totalTurnAround += p[i].turnAround;

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, p[i].burst, p[i].wait, p[i].turnAround);
    }
    float avgWait = totalWaiting/n;
    float avgTurnAround = totalTurnAround/n;
    printf("\nAverage Waiting Time : %.3f", avgWait);
    printf("\nAverage TurnAround Time : %.3f", avgTurnAround);

    return 0;
}
