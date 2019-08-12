#include <stdio.h>
 
int main()
{
    int a;
 
    FILE *f=fopen("input.txt", "r");
    fscanf(f, "%d", &a);
    fclose(f);
 
    f=fopen("output.txt", "w");
    fprintf(f,"%d9%d", a, 9-a);
    return 0;
}