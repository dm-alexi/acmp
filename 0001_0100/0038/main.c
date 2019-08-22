#include <stdio.h>
#include <stdlib.h>

#define KEY 100000

int play(int *p, int left, int right, int n, int *t)
{
    int l, r;

    if (t[left * n + right] == KEY)
    {
        l = p[left] - play(p, left + 1, right, n, t);
        r = p[right] - play(p, left, right - 1, n, t);
        t[left * n + right] = l > r ? l : r;
    }
    return t[left * n + right];
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, *t;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    t = (int*)malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; ++i)
        t[i] = KEY;
    for (int i = 0; i < n; ++i)
    {
        fscanf(f, "%d", p + i);
        t[n * i + i] = p[i];
    }
    n = play(p, 0, n - 1, n, t);
    fprintf(q, !n ? "0" : n > 0 ? "1" : "2");
    return 0;
}
