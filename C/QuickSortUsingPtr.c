#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
    char EmpNm[5];
    int EmpID;
};

int int_call(const void *a1, const void *b1)
{
    const int *a = (const int *)a1;
    const int *b = (const int *)b1;
    if (*a > *b)
        return 1;
    else if (*a == *b)
        return 0;
    else
        return -1;
}

int string_call(const void *a1, const void *b1)
{
    const char *a = (const char *)a1;
    const char *b = (const char *)b1;
    return (strcmp(a, b));
}

int main(void)
{
    int arr[5] = {20, 30, 40, 10, 50};
    struct s EmpRec[5];
    int i, j;
    strcpy(EmpRec[0].EmpNm, "AAA");
    EmpRec[0].EmpID = 300;
    strcpy(EmpRec[1].EmpNm, "CCC");
    EmpRec[1].EmpID = 200;
    strcpy(EmpRec[2].EmpNm, "EEE");
    EmpRec[2].EmpID = 100;
    strcpy(EmpRec[3].EmpNm, "BBB");
    EmpRec[3].EmpID = 400;
    strcpy(EmpRec[4].EmpNm, "DDD");
    EmpRec[4].EmpID = 500;

    qsort(arr, 5, sizeof(int), int_call);
    qsort(EmpRec, 5, sizeof(struct s), string_call);

    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    printf("\nSorting Structure\n");
    for (i = 0; i < 5; i++)
        printf("\n%s\t%d", EmpRec[i].EmpNm, EmpRec[i].EmpID);
}