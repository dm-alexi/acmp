#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct edge
{
    int a, b, dist;
} edge;

int reach(int n, int m, edge *e, int a)
{
    char *r = (char*)calloc(n, 1);
    int x;

    r[a] = 1;
    for (int i = 0; i < n; ++i)
    {
        int stop = 1;
        for (int j = 0; j < m; ++j)
            if (r[e[j].a] && !r[e[j].b])
                stop = 0, r[e[j].b] = 1;
        if (stop || r[n - 1])
            break;
    }
    x = r[n - 1];
    free(r);
    return(x);
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, stop;
    long long *d;
    edge *e;
    char r = -1;

    fscanf(f, "%d%d", &n, &m);
    e = (edge*)malloc(sizeof(edge) * m);
    for (int i = 0; i < m; ++i)
    {
        fscanf(f, "%d%d%d", &(e[i].a), &(e[i].b), &(e[i].dist));
        --e[i].a, --e[i].b;
    }
    d = (long long*)malloc(sizeof(long long) * n);
    for (int i = 1; i < n; ++i)
        d[i] = LLONG_MIN;
    d[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        stop = 1;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] > LLONG_MIN && d[e[j].b] < d[e[j].a] + e[j].dist)
                stop = 0, d[e[j].b] = d[e[j].a] + e[j].dist;
        if (stop)
            break;
    }
    if (d[n - 1] > LLONG_MIN)
    {
        r = 0;
        if (!stop)
            for (int j = 0; j < m; ++j)
                if (d[e[j].a] > LLONG_MIN && d[e[j].b] < d[e[j].a] + e[j].dist && reach(n, m, e, e[j].a) && (r = 1))
                    break;
    }
    if (!r)
        fprintf(q, "%I64d", d[n - 1]);
    else
        fprintf(q, r > 0 ? ":)" : ":(");
    return 0;
}
