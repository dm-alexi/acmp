#include <stdio.h>

int main()
{
    int m = 0, t = 0;
    char c;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    while ((c = getc(f)) != EOF)
    {
        if (c == '0')
            ++t;
        else
        {
            if (t > m)
                m = t;
            t = 0;
        }
    }
    fprintf(q, "%d", m);
    return 0;
}
