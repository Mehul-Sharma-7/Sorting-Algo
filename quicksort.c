#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int temp;
    int pivot = low;
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= A[pivot])
        {
            i++;
        }
        while (A[j] > A[pivot])
        {
            j--;
        }
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    
    temp = A[pivot];
    A[pivot] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {12, 34, 23, 5, 67, 48};
    int n = 6;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}