#include <stdio.h>
#include <conio.h>

int i, j, temp, max, count, maxDig = 0, c = 0;
int a[15], a1[15];
void arrange(int k, int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a1[i] > a1[j])
            {
                temp = a1[i];
                a1[i] = a1[j];
                a1[j] = temp;

                temp = (a[i] % 10);
                a[i] = a[j] % 10;
                a[j] = temp;
            }
        }
    }
}

int main(void)
{
    int t1, t2, k, t, n = 1;
    printf("\nEnter the number of elements: ");
    scanf("%d", &count);

    printf("\nEnter Elements: \n");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &a[i]);
        a1[i] = a[i];
    }

    for (i = 0; i < count; i++)
    {
        t = a[i];
        while (t > 0)
        {
            c++;
            t /= 10;
        }
        if (maxDig < c)
            maxDig = c;
        c = 0;
    }

    while (--maxDig)
        n = n * 10;

    for (i = 0; i < count; i++)
    {
        max = a[i] / n;
        t = i;
        for (j = i + 1; j < count; j++)
        {
            if (max > (a[j] / n))
            {
                max = a[j] / n;
                t = j;
            }
        }

        temp = a1[t];
        a1[t] = a1[i];
        a1[i] = temp;

        temp = a[t];
        a[t] = a[i];
        a[i] = temp;
    }
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = a[i] / n;
            for (j = i + 1; t1 = (a[j] / n); j++)
                ;
            arrange(i, j);
            i = j;
        }
        n = n / 10;
    }

    printf("\nSorted: (PostmanSort)\n");
    for (i = 0; i < count; i++)
        printf("%d ", a1[i]);
    printf("\n");
}