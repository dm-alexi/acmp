#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int i, k = 0, n = 0;
    char s[1002];

    fscanf(f, "%s", s);
    if (s[1] != '\0')
        ++k;
    for(i = 0; s[i]; ++i)
        n += s[i] - '0';
    while (n > 9 && ++k)
    {
        int h = 0;
        while (n > 0)
            h += n % 10, n /= 10;
        n = h;
    }
    fprintf(q,"%d %d", n, k);
    return 0;
}
