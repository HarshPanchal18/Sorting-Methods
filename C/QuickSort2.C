#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define STACKSIZE 50

struct bounds
{
	int lb, ub;
};
struct stack
{
	int top;
	struct bounds items[STACKSIZE];
};

void quick(int x[], int n);
int partition(int x[], int lb, int ub);
void show(int x[], int lb, int ub);
void push(struct stack *ps, struct bounds x);
struct bounds pop(struct stack *ps);
int empty(struct stack *ps);

int main(void)
{
	int i, n, x[20] = {0};
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);

	printf("\nEnter the elements: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	quick(x, n);

	printf("\nSorted array is: \n");
	for (i = 0; i < n; i++)
		printf("%d\t", x[i]);
}

void quick(int x[], int n)
{
	int temp, j;
	struct bounds b;
	struct stack s;
	s.top = -1;
	b.lb = 0;
	b.ub = n - 1;
	push(&s, b);

	while (!empty(&s))
	{
		b = pop(&s);
		while (b.ub > b.lb)
		{
			j = partition(x, b.lb, b.ub);
			if (j - b.lb > b.ub - j)
			{
				temp = b.ub;
				b.ub = j - 1;
				push(&s, b);

				b.lb = j + 1;
				b.ub = temp;
			}
			else
			{
				temp = b.lb;
				b.lb = j + 1;
				push(&s, b);

				b.ub = j - 1;
				b.lb = temp;
			}
		}
	}
}

int partition(int x[], int lb, int ub)
{
	int a, down, up, temp;
	a = x[lb];
	up = ub;
	down = lb;
	while (down < up)
	{
		while (x[down] <= a && down < ub)
			down++;

		while (x[up] > a)
			up--;

		if (down < up)
		{
			temp = x[down];
			x[down] = x[up];
			x[up] = temp;
		}
	}
	x[lb] = x[up];
	x[up] = a;
	// show(x, lb, ub);
	return up;
}

/*
void show(int x[], int lb, int ub)
{
	for (int i = lb; i <= ub; i++)
		printf("%3d", x[i]);
	printf("\n");
}
*/

void push(struct stack *ps, struct bounds x)
{
	if (ps->top == STACKSIZE - 1)
	{
		printf("\nStack overflow\n");
		getch();
		exit(0);
	}
	ps->items[++(ps->top)] = x;
}

struct bounds pop(struct stack *ps)
{
	if (empty(ps))
	{
		printf("\nEmpty stack\n");
		getch();
		exit(0);
	}
	return (ps->items[(ps->top)--]);
}

int empty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;
	else
		return 0;
}