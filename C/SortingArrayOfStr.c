#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    return strcmp(b, a);
}

int distinct(const char *a)
{
    int x[26];

    for (int i = 0; i < 26; i++)
    {
        x[i] = 0;
        // printf("x[%d] = %d\t", i,x[i]);
    }

    for (int i = 0; a[i] != '\0'; i++)
        x[a[i] - 'a']++;

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (x[i] >= 1)
            count++;
    }
    // printf("%s=%d\n", a, count);
    return count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int d1 = distinct(a), d2 = distinct(b);
    int x = strcmp(a, b);
    if (d1 > d2)
        return 1;

    else if (d1 == d2)
        if (x > 0)
            return 1;
        else
            return 0;

    else
        return 0;
}

int sort_by_length(const char *a, const char *b)
{
    int x = strlen(a), y = strlen(b), z = strcmp(a, b);

    if (x == y)
        if (z > 0)
            return 1;
        else
            return 0;

    else if (x > y)
        return 1;
    else
        return 0;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    int sorted = 0;
    int top = len - 1;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < top; i++)
        {
            if (cmp_func(arr[i], arr[i + 1]) > 0)
            {
                /* if(cmp_func(arr[j], arr[j+1]) -- it is a generalised function pointer
                    which holds the address of different sort functions and call them accordingly*/

                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = 0;
            }
        }
        top--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}

/*
INPUT
4
wkue
qoi
sbv
fekls

OUTPUT
fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls
*/
