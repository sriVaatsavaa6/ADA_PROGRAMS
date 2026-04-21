#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j, temp;
    for(j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int n, i, *a;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if(n <= 5000)
    {
        printf("Enter n greater than 5000\n");
        return 0;
    }

    a = (int *)malloc(n * sizeof(int));
    if(a == NULL)
        return 0;

    srand(time(0));
    for(i = 0; i < n; i++)
        a[i] = rand() % 10000;

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting = %lf seconds\n", time_taken);

    free(a);
    return 0;
}
