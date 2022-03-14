#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int nb, np, i, j, flag = 1, temp, fragment[20];
    static int bArray[20], pArray[20];
    int highest = 0;
    // Input no of blocks and their size
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

    printf("\n\nProcess \n\n");
    printf("\nProcess Name   Process Size   Block ID     Block Size");
    for (i = 1; i <= np && pArray[i] != 0; i++)
    {
        printf("\nProcess %s\t%d\t\t%d\t\t%d", p[i].name, p[i].size, pArray[i], b[pArray[i]].size);
    }
    return 0;
}
