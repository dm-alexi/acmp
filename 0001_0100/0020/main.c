#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, max = 1, c, res, lres, last, cur;

    fscanf(f, "%d", &n);
    if (n > 1)
    {
        fscanf(f, "%d", &last);
        lres = 0;
        c = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            fscanf(f, "%d", &cur);
            res = cur == last ? 0 : cur < last ? -1 : 1;
            if (res == lres || res == 0)
            {
                if (c > max)
                    max = c;
                c = res ? 1 : 0;
            }
            ++c;
            lres = res;
            last = cur;
        }
        if (c > max)
            max = c;
    }
    fprintf(q, "%d", max);
    return 0;
}
