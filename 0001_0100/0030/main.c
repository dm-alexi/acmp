#include <stdio.h>

int main()
{
    int a[10] = {0}, i, s[3], t[3];
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%d:%d:%d\n%d%:%d:%d", s, s + 1, s + 2, t, t + 1,  t + 2);
    for (;;)
    {
        for (i = 0; i < 3; ++i)
            ++a[s[i] / 10], ++a[s[i] % 10];
        if (s[0] == t[0] && s[1] == t[1] && s[2] == t[2])
            break;
        if (++s[2] == 60)
        {
            s[2] = 0;
            if (++s[1] == 60)
                s[1] = 0, ++s[0];
        }
    }
    for(i = 0; i <= 9; ++i)
        fprintf(q, "%d\n", a[i]);
    return 0;
}
