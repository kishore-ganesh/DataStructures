#include <stdio.h>
#include <stdlib.h>

void display(int *A, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int partition(int *A, int lo, int hi)
{
    int pivot = A[hi - 1];
    printf("%d\n", pivot);
    int i = lo;

    for (int j = lo; j < hi - 1; j++)
    {
        if (A[j] < pivot)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            i++;
        }
    }

    int t = A[i];
    A[i] = A[hi - 1];
    A[hi - 1] = t;
    //display(A);
    return i;
}

void quicksort(int *a, int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(a, lo, hi);
        //    printf("%d\n", p);

        quicksort(a, p + 1, hi);
        if (p > 0)
        {
            quicksort(a, lo, p);
        }
    }
}

int main()
{
    int *A;
    int N;
    scanf("%d", &N);

    A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }

    quicksort(A, 0, N);
    display(A, N);
}