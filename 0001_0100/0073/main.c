#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    char s[256];

    fscanf(f, "%s", s);
     for (int i = 0, n = strlen(s); i < n; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
            s[i] -= '0';
        else s[i] -= 'A' - 10;
        s[i] = (s[i] - (i + 1) % 27 + 27) % 27;
        if (s[i])
            s[i] += 'a' - 1;
        else s[i] = ' ';
    }
    fprintf(q, s);
    return 0;
}
