#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    char s[3];

    fscanf(f, "%s", s);
    fprintf(f, ((s[0] - 'A' + 1 + s[1] - '0') % 2) ? "WHITE" : "BLACK");
    return 0;
}
