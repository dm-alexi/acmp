#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void quicksort(int a[], int left, int right)
{
    int last;
    if (left >= right)
        return;
    swap(a, left, (left + right) / 2);
    last = left;
    for (int i = left + 1; i <= right; ++i)
        if (a[i] < a[left])
            swap(a, ++last, i);
    swap(a, left, last);
    quicksort(a, left, last - 1);
    quicksort(a, last + 1, right);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p;
    double s;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%d", p + i);
    fscanf(f, "%lf", &s);
    quicksort(p, 0, n - 1);
    for (int i = 0; i < n; ++i)
        if (p[i] > s)
            s = (s + p[i]) / 2;
    fprintf(q, "%f", s);
    return 0;
}
