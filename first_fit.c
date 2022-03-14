#include<stdio.h>
#include<stdlib.h>

struct Process
{
    int size;
    int id;
    char name[10];
}p[20] = {0};

struct Block
{
    int size;
    int id;
}b[20] = {0};



int main() {
    int nb, np, i, j, flag = 1;
    //Input no of blocks and their size
    printf("Enter number of blocks : ");
    scanf("%d",&nb);
    for(i = 0; i < nb; i++) {
        printf("Enter size of block %d : ", i + 1);
        scanf("%d",&b[i].size);
    }
    //input no of process and their size and name
    printf("\nEnter number of processes : ");
    scanf("%d",&np);
    for(i = 0; i < np; i++) {
        printf("Enter name of process %d : ", i +1);
        scanf("%s",p[i].name);
        printf("Enter size of process %d : ", i + 1);
        scanf("%d",&p[i].size);
    }

    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(b[j].id == 0 && p[i].size <= b[j].size) {
                b[j].id = i + 1;
                p[i].id = j + 1;
                flag = 1;
                break;
            }
        }
    }

    printf("\nBlock\n\n");
    printf("\nBlock ID   Block Size   Process Name    Process Size");
    for(i = 0; i < nb; i++) {
        if(b[i].id) {
            printf("\nBlock %d\t\t%d\t%s\t\t%d", i + 1, b[i].size, p[b[i].id - 1].name, p[b[i].id - 1].size);
        }
        else {
            printf("\nBlock %d\t\t%d\tEmpty\t\tEmpty", i + 1, b[i].size);
        }
    }

    printf("\n\nProcess \n\n");
    printf("\nProcess Name   Process Size   Block ID     Block Size");
    for(i = 0; i < np; i++) {
        if(p[i].id) {
            printf("\nProcess %s\t%d\t\t%d\t\t%d", p[i].name, p[i].size, p[i].id, b[p[i].id - 1].size);
        }
        else {
            printf("\nProcess %s\t%d\t\tWaiting\t\tWaiting", p[i].name, p[i].size);
        }
    }
    return 0;
}
