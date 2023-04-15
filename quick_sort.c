#include <libc.h>

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) 
	{
        while (i <= high && arr[i] < pivot)
            i++;
        while (j >= low + 1 && arr[j] > pivot)
            j--;
        if (i > j)
            break;
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    int arr[] = {5, 9, 3, 6, 2, 8, 1, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    quickSort(arr, 0, n - 1);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
