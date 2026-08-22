#include <stdio.h>
#include <math.h>
#define MAX 100

struct Stack
{
    int disk[MAX];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int disk)
{
    s->top++;
    s->disk[s->top] = disk;
}

int pop(struct Stack *s)
{
    int value = s->disk[s->top];
    s->top--;
    return value;
}

int peek(struct Stack *s)
{
    return s->disk[s->top];
}

void moveDisk(struct Stack *a, struct Stack *b,
              char nameA, char nameB)
{
    int diskA, diskB;

    if (isEmpty(a)){
        diskB = pop(b);
        push(a, diskB);
        printf("Move disk %d from %c to %c\n",diskB, nameB, nameA);
    }
    else if (isEmpty(b)){
        diskA = pop(a);
        push(b, diskA);
        printf("Move disk %d from %c to %c\n", diskA, nameA, nameB);
    }else if (peek(a) < peek(b)){
        diskA = pop(a);
        push(b, diskA);
        printf("Move disk %d from %c to %c\n",diskA, nameA, nameB);
    }else{
        diskB = pop(b);
        push(a, diskB);
        printf("Move disk %d from %c to %c\n", diskB, nameB, nameA);
    }
}

int main()
{
    struct Stack source, auxiliary, destination;
    int n, i, totalMoves;

    initialize(&source);
    initialize(&auxiliary);
    initialize(&destination);

    printf("Enter number of disks: ");
    scanf("%d", &n);

    for (i = n; i >= 1; i--)
    {
        push(&source, i);
    }

    totalMoves = pow(2, n) - 1;
    if (n % 2 != 0)
    {
        for (i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(&source, &destination, 'S', 'D');

            else if (i % 3 == 2)
                moveDisk(&source, &auxiliary, 'S', 'A');

            else
                moveDisk(&auxiliary, &destination, 'A', 'D');
        }
    }else{
        for (i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
                moveDisk(&source, &auxiliary, 'S', 'A');

            else if (i % 3 == 2)
                moveDisk(&source, &destination, 'S', 'D');

            else
                moveDisk(&auxiliary, &destination, 'A', 'D');
        }
    }
    return 0;
}