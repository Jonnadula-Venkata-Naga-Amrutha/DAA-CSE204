#include <stdio.h>
#include <limits.h>

int main()
{
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n)
    {
        printf("Invalid value of k\n");
        return 0;
    }

    int count = 0;
    for (int i=0; i<k; i++)
    {
        int min = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        count = min;
        arr[index] = INT_MAX;
    }

    printf("Kth smallest element = %d\n",count);

    return 0;
}