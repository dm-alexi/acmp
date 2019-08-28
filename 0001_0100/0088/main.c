#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, i, j, t[100][100];

    fscanf(f, "%d", &n);
    for (i = 0; i < n * n; ++i)
        for(j = 0; j < n * n; ++j)
            fscanf(f, "%d", t[i] + j);
    for (i = 0; i < n * n; ++i)
    {
        char l[101] = {0}, c[101] = {0}, k[101] = {0};
        for (j = 0; j < n * n; ++j)
            ++l[t[i][j]], ++c[t[j][i]], ++k[t[i / n * n + j / n][i % n * n + j % n]];
        for (j = 1; j <= n * n; ++j)
            if (l[j] != 1 || c[j] != 1 || k[j] != 1)
                break;
        if (j <= n * n)
            break;
    }
    fprintf(q, i < n * n ? "Incorrect" : "Correct");
    return 0;
}
