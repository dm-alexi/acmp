#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    char *s = "qwertyuiopasdfghjklzxcvbnmq", c;

    fscanf(f, "%c", &c);
    while(*s++ != c);
    putc(*s, q);
    return 0;
}
