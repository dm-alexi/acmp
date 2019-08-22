#include <stdio.h>
 
int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a;

    fscanf(f, "%d", &a);
    fprintf(f, "%d9%d", a, 9 - a);
    return 0;
}