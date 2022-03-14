#include <stdio.h>
#include <stdlib.h>
int maxRes[100][100], allocRes[100][100], needRes[100][100], availRes[100];
int np, nr;

void input()
{
    int i, j;
    // input no of processes and resources
    printf("Enter number of processes : ");
    scanf("%d", &np);
    printf("\nEnter number of resources : ");
    scanf("%d", &nr);
    // input allocation matrix
    printf("\nEnter allocated resource matrix : \n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &allocRes[i][j]);
        }
    }
    // input maximum resoucres required matrix
    printf("\nEnter maximum resource matrix : \n");
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &maxRes[i][j]);
        }
    }
    // available resoucres
    printf("\nEnter available resources : \n");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &availRes[i]);
    }
}

void banker_algo()
{
    int finish[100], i, j, k, safe[100], flag = 1;
    for (i = 0; i < np; i++)
    {
        finish[i] = 0;
    }
    // need matrix
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            needRes[i][j] = maxRes[i][j] - allocRes[i][j];
        }
    }
    // main
    while (flag)
    {
        flag = 0;
        for (i = 0; i < np; i++)
        {
            int c = 0;
            for (j = 0; j < nr; j++)
            {
                if (finish[i] == 0 && needRes[i][j] <= availRes[j])
                {
                    c++;
                    if (c == nr)
                    {
                        for (k = 0; k < nr; k++)
                        {
                            availRes[k] += allocRes[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        printf("P%d->", i + 1);
                    }
                }
            }
        }
    }
    int count = 0;
    for (i = 0; i < np; i++)
    {
        if (finish[i] == 1)
        {
            count++;
        }
    }
    if (count == np)
    {
        printf("\nSystem is in safe state");
    }
    else
    {
        printf("\nDeadlock !!!!!");
    }
}

void show()
{
    int i, j;
    printf("\nProcess\t\tAllocation\tMax\t\tNeed\t\tAvailable");
    for (i = 0; i < np; i++)
    {
        printf("\nProcess %d", i + 1);
        printf("\t");
        for (j = 0; j < nr; j++)
        {
            printf("%d ", allocRes[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < nr; j++)
        {
            printf("%d ", maxRes[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < nr; j++)
        {
            printf("%d ", needRes[i][j]);
        }
        printf("\t\t");
        if (i == 0)
        {
            for (j = 0; j < nr; j++)
            {
                printf("%d ", availRes[j]);
            }
        }
    }
}

int main()
{
    printf("\nImplementation of Banker's Algorithm\n");
    input();
    banker_algo();
    show();
    return 0;
}
