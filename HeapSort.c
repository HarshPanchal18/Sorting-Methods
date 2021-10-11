#include <stdio.h>
int array[20], n;

void insert(int num, int loc)
{
    int par;
    while (loc > 0)
    {
        par = (loc - 1) / 2;
        if (num <= array[par])
        {
            array[loc] = num;
            return;
        }
        array[loc] = array[par];
        loc = par;
    }
    array[0] = num;
}

void create_heap()
{
    int i;
    for (i = 0; i < n; i++)
        insert(array[i], i);
}

void delete_root(int last)
{
    int i = 0, left, right, temp;

    temp = array[i]; //exchange large with the root
    array[i] = array[last];
    array[last] = temp;
    left = 2 * i + 1;
    right = 2 * i + 2;

    while (right < last)
    {
        if (array[i] >= array[right] && array[i] >= array[left])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left = last - 1 && array[i] < array[left])
    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}

void display()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void heap_sort()
{
    int last = 0;
    for (last = n - 1; last > 0; last--)
        delete_root(last);
}

int main()
{
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter %d number: ", i + 1);
        scanf("%d", &array[i]);
    }
    create_heap();

    printf("\nHeap is :\n");
    display();

    heap_sort();
    printf("\nSorted list: \n");
    display();
    return 0;
}