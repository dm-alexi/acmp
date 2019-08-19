#include <stdio.h>

int main()
{
    int a, b;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d", &a, &b);
    fprintf(q, "%c", (a > b) ? '>' : (a < b) ? '<' : '=');
    return 0;
}
