#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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

    srand(time(0));
    for(i = 0; i < n; i++)
        a[i] = rand() % 10000;

    start = clock();
    selectionSort(a, n);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting = %lf seconds\n", time_taken);

    free(a);
    return 0;
}
