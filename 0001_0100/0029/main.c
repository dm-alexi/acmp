#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a < b) ? (a) : (b))

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, s, prev = 0;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%d", p + i);
    s = n == 1 ? 0 : abs(p[1] - p[0]);
    for (int i = 2; i < n; ++i)
    {
        int t = s;
        s = min(s + abs(p[i] - p[i - 1]), prev + 3 * abs(p[i] - p[i - 2]));
        prev = t;
    }
    fprintf(q, "%d", s);
    return 0;
}
