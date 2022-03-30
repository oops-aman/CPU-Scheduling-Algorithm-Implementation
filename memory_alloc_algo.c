#include <stdio.h>
#include <stdlib.h>

int nb, np, i, j, flag = 1, temp, fragment[20];
static int bArray[20], pArray[20];
int lowest = 9999;
int highest = 0;

struct Process
{
    int size;
    int id;
    char name[10];
} p[20] = {0};

struct Block
{
    int size;
    int id;
} b[20] = {0};

void input_data()
{
    printf("Enter number of blocks : ");
    scanf("%d", &nb);
    for (i = 1; i <= nb; i++)
    {
        printf("Enter size of block %d : ", i);
        scanf("%d", &b[i].size);
    }
    // input no of process and their size and name
    printf("\nEnter number of processes : ");
    scanf("%d", &np);
    for (i = 1; i <= np; i++)
    {
        printf("Enter name of process %d : ", i);
        scanf("%s", p[i].name);
        printf("Enter size of process %d : ", i);
        scanf("%d", &p[i].size);
    }
}

void first_fit()
{
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (b[j].id == 0 && p[i].size <= b[j].size)
            {
                b[j].id = i + 1;
                p[i].id = j + 1;
                flag = 1;
                break;
            }
        }
    }
    printf("\n\First Fit \n\n");
    printf("\nProcess Name   Process Size   Block ID     Block Size");
    for (i = 0; i < np; i++)
    {
        if (p[i].id)
        {
            printf("\nProcess %s\t%d\t\t%d\t\t%d", p[i].name, p[i].size, p[i].id, b[p[i].id - 1].size);
        }
        else
        {
            printf("\nProcess %s\t%d\t\tWaiting\t\tWaiting", p[i].name, p[i].size);
        }
    }
}

void best_fit()
{
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bArray[j] != 1)
            {
                temp = b[j].size - p[i].size;
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        pArray[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        fragment[i] = lowest;
        bArray[pArray[i]] = 1;
        lowest = 10000;
    }
    printf("\n\Best Fit \n\n");
    printf("\nProcess Name   Process Size   Block ID     Block Size");
    for (i = 1; i <= np && pArray[i] != 0; i++)
    {
        printf("\nProcess %s\t%d\t\t%d\t\t%d", p[i].name, p[i].size, pArray[i], b[pArray[i]].size);
    }
}

void worst_fit()
{
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bArray[j] != 1)
            {
                temp = b[j].size - p[i].size;
                if (temp >= 0)
                {
                    if (highest < temp)
                    {
                        pArray[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        fragment[i] = highest;
        bArray[pArray[i]] = 1;
        highest = 1;
    }
    printf("\n\Worst Fit \n\n");
    printf("\nProcess Name   Process Size   Block ID     Block Size");
    for (i = 1; i <= np && pArray[i] != 0; i++)
    {
        printf("\nProcess %s\t%d\t\t%d\t\t%d", p[i].name, p[i].size, pArray[i], b[pArray[i]].size);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nMemory Allocation Schemes\n\n");
        printf("\n1. Input Data\n2. First Fit\n3. Best Fit\n4. Worst Fit\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input_data();
            break;

        case 2:
            first_fit();
            break;

        case 3:
            best_fit();
            break;

        case 4:
            worst_fit();
            break;

        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}
