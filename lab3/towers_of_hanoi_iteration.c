#include <stdio.h>
#include <math.h>

#define MAX 100

int stackA[MAX], stackB[MAX], stackC[MAX];
int topA = -1, topB = -1, topC = -1;

void push(int stack[], int *top, int disk)
{
    (*top)++;
    stack[*top] = disk;
}

int pop(int stack[], int *top)
{
    int disk = stack[*top];
    (*top)--;
    return disk;
}

void moveDisk(char from, char to,
              int stack1[], int *top1,
              int stack2[], int *top2)
{
    int disk;

    if (*top1 == -1)
    {
        disk = pop(stack2, top2);
        push(stack1, top1, disk);

        printf("Move disk %d from %c to %c\n",
               disk, to, from);
    }

    else if (*top2 == -1)
    {
        disk = pop(stack1, top1);
        push(stack2, top2, disk);

        printf("Move disk %d from %c to %c\n",
               disk, from, to);
    }

    else if (stack1[*top1] < stack2[*top2])
    {
        disk = pop(stack1, top1);
        push(stack2, top2, disk);

        printf("Move disk %d from %c to %c\n",
               disk, from, to);
    }

    else
    {
        disk = pop(stack2, top2);
        push(stack1, top1, disk);

        printf("Move disk %d from %c to %c\n",
               disk, to, from);
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--)
    {
        push(stackA, &topA, i);
    }

    int moves=pow(2,n)-1;

    for (int i = 1; i <= moves; i++)
    {
        if (n % 2 == 1)
        {
            if (i % 3 == 1)
            {
                moveDisk('A', 'C',
                         stackA, &topA,
                         stackC, &topC);
            }
            else if (i % 3 == 2)
            {
                moveDisk('A', 'B',
                         stackA, &topA,
                         stackB, &topB);
            }
            else
            {
                moveDisk('B', 'C',
                         stackB, &topB,
                         stackC, &topC);
            }
        }
        else
        {
            if (i % 3 == 1)
            {
                moveDisk('A', 'B',
                         stackA, &topA,
                         stackB, &topB);
            }
            else if (i % 3 == 2)
            {
                moveDisk('A', 'C',
                         stackA, &topA,
                         stackC, &topC);
            }
            else
            {
                moveDisk('B', 'C',
                         stackB, &topB,
                         stackC, &topC);
            }
        }
    }

    return 0;
}