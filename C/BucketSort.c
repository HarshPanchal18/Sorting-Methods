#include <stdio.h>
#include <malloc.h>

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void display()
{
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

int large_dig(struct node *p)
{
    int large = 0, ndig = 0;
    while (p != NULL)
    {
        if (p->info > large)
            large = p->info;
        p = p->link;
    }
    printf("\nLargest Element is: %d\n", large);
    while (large != 0)
    {
        ndig++;
        large = large / 10;
    }
    printf("\nNumber of digits: %d\n", ndig);
    return ndig;
}

int digit(int number, int k)
{
    int digit, i;
    for (i = 0; i <= k; i++)
    {
        digit = number % 10;
        number = number / 10;
    }
    return digit;
}

void radix_sort()
{
    int i, k, maxdig, mindig, least_sig, most_sig, dig;
    struct node *p, *rear[10], *front[10];

    least_sig = 1;
    most_sig = large_dig(start);

    for (k = least_sig; k <= most_sig; k++)
    {
        printf("\nPass %d: Examining %dth digit from right..", k, k);
        for (i = 0; i <= 9; i++)
        {
            rear[i] = NULL;
            front[i] = NULL;
        }
        maxdig = 0;
        mindig = 9;
        p = start;
        while (p != NULL)
        {
            dig = digit(p->info, k);
            if (dig > maxdig)
                maxdig = dig;
            if (dig < mindig)
                mindig = dig;

            if (front[dig] == NULL)
                front[dig] = p;
            else
                rear[dig]->link = p;
            rear[dig] = p;
            p = p->link;
        }

        printf("\nMin_dig = %d  Max_dig = %d\n", mindig, maxdig);
        start = front[mindig]; // join all the queues to form the new linked list
        for (i = mindig; i < maxdig; i++)
        {
            if (rear[i + 1] != NULL)
                rear[i]->link = front[i + 1];
            else
                rear[i + 1] = rear[i];
        }
        rear[maxdig]->link = NULL;
        printf("\n New generated list :  ");
        display();
    }
}

int main()
{
    struct node *tmp, *q;
    int i, n, item;
    printf("Enter the number of elements in the list : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &item);

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = item;
        tmp->link = NULL;

        if (start == NULL)
            start = tmp;
        else
        {
            q = start;
            while (q->link != NULL)
                q = q->link;
            q->link = tmp;
        }
    }

    printf("\nUnsorted list: \n");
    display();

    radix_sort();

    printf("\nSorted list: \n");
    display();
    return 0;
}
