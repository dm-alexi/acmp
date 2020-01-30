#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i = 10, j = 9;
    char s[38895] = "123456789", t[6];

    for (; i < 100; ++i, j += 2)
		sprintf(s + j, "%d", i);
	for (; i < 1000; ++i, j += 3)
		sprintf(s + j, "%d", i);
	for (; i <= 10000; ++i, j += 4)
		sprintf(s + j, "%d", i);
    fscanf(f, "%s", t);
    fprintf(q, "%d", strstr(s, t) - s + 1);
    return 0;
}
