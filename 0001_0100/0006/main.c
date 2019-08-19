#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[5];
    int i;

    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    for (i = 0; i < 5; ++i)
        s[i] = getc(f);
    if (s[0] < 'A' || s[0] > 'H' || s[3] < 'A' || s[3] > 'H' || s[1] < '1'
        || s[1] > '8' || s[4] < '1' || s[4] > '8' || s[2] != '-')
        fprintf(q, "ERROR");
    else if (abs((s[0] - s[3]) * (s[1] - s[4])) == 2)
        fprintf(q,"YES");
    else
        fprintf(q,"NO");
    return 0;
}
