#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (a[j] > pivot)
        {
            j--;
        }
        while (a[i] <= pivot && i < j)
        {
            i++;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
int main()
{
    int arr[5] = {12, 56, 9, 0, 45};

    printf("BEFORE SORTING =\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, 4);

    printf("\nAFTER SORTING =\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}