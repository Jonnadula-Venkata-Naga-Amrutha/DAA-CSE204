#include<stdio.h>
#define max 10
int hash[max];
int frequency[max];
void initialize()
{
    for(int i = 0; i < max; i++)
    {
        hash[i] = -1;
        frequency[i] = 0;
    }
}
void insert(int key)
{
    int index = key % max;
    while(hash[index] != -1)
    {
        if(hash[index] == key)
        {
            frequency[index]++;
            return;
        }
        index = (index + 1) % max;
    }
    hash[index] = key;
    frequency[index] = 1;
}
void display()
{
    printf("\nElement\tFrequency\n");

    for(int i = 0; i < max; i++)
    {
        if(hash[i] != -1)
        {
            printf("%d\t%d\n", hash[i], frequency[i]);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of elements = ");
    scanf("%d", &n);
    int a[n];
    initialize();
    printf("Enter %d numbers = ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    display();

    return 0;
}