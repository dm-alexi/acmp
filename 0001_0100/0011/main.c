#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int k, n, i;
    char a[301][91] = {{0}};

    fscanf(f, "%d%d", &k, &n);
    a[0][0] = a[1][0] = 1;
    for (i = 2; i <= n; ++i)
    {
        for (int j = 0; j < 91; ++j)
        {
            a[i][j] += 2 * a[i - 1][j];
            if(a[i][j] > 9)
                a[i][j] -= 10, ++a[i][j + 1];
        }
        if (i > k)
            for (int j = 0; j < 91; ++j)
            {
                a[i][j] -= a[i - k - 1][j];
                if(a[i][j] < 0)
                    a[i][j] += 10, --a[i][j + 1];
            }
    }
    for (i = 90; a[n][i] == 0; --i);
    for (; i >= 0; --i)
        fprintf(q, "%c", a[n][i] + '0');
    return 0;
}
