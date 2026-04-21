#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for(i = 0; i < n1; i++) L[i] = a[l + i];
    for(j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    
    i = j = 0; k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
    
    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
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
    if(a == NULL) return 0;

    srand(time(0));
    for(i = 0; i < n; i++)
        a[i] = rand() % 10000;

    start = clock();
    mergeSort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting = %lf seconds\n", time_taken);

    free(a);
    return 0;
}
