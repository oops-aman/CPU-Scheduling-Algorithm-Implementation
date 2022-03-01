// C Program to implement non-preemptive Shortest Job First Scheduling algorithm

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter number of processes : ");
    scanf("%d", &n);
    int p[n], burst[n], wait[n], turnAround[n], i, j, totalWaiting = 0, totalTurnAround = 0;
    for (i = 0; i < n; i++)
    {
        printf("P[%d] : ", i + 1);
        scanf("%d", &burst[i]);
        p[i] = i + 1;
    }

    // sorting of burst times
    for (i = 0; i < n; i++)
    {
        int pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (burst[j] < burst[pos])
            {
                pos = j;
            }
        }
        int temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wait[0] = 0;
    for (i = 1; i < n; i++)
    {
        wait[i] = 0;
        for (j = 0; j < i; j++)
        {
            wait[i] += burst[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnAround Time");
    for (i = 0; i < n; i++)
    {
        turnAround[i] = burst[i] + wait[i];
        totalWaiting += wait[i];
        totalTurnAround += turnAround[i];

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], burst[i], wait[i], turnAround[i]);
    }
    float avgWait = (float)totalWaiting / n;
    float avgTurnAround = (float)totalTurnAround / n;
    printf("\nAverage Waiting Time : %.3f", avgWait);
    printf("\nAverage TurnAround Time : %.3f", avgTurnAround);

    return 0;
}
