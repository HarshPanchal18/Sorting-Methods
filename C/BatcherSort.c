#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) \
    {              \
        int t = A; \
        A = B;     \
        B = t;     \
    }
#define compexch(A, B) \
    if (less(B, A))    \
    exch(A, B)

void batchersort(int a[], int l, int r)
{
    int N = r - l + 1;

    for (int p = 1; p < N; p += p)
        for (int k = p; k > 0; k /= 2)
            for (int j = k % p; j + k < N; j += (k + k))
                for (int i = 0; i < k; i++)
                    if (j + i + k < N)
                        if ((j + i) / (p + p) == (j + i + k) / (p + p))
                            compexch(a[l + j + i], a[l + j + i + k]);
}

void print_list(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int N = 7, i;
    int *a;

    srand(time(NULL));

    a = malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
        a[i] = rand() % 100;

    printf("Before: ");
    print_list(N, a);

    batchersort(a, 0, N - 1);

    printf("After: ");
    print_list(N, a);
    
    return 0;
}
