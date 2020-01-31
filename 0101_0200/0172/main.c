#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char *s, str[102], t[12];
	int k, n, m = 0, l;

	fscanf(f, "%s%d", str, &k);
	n = strlen(s = str);
	l = k;
    while (l)
        ++m, l /= 10;
    while (n > m)
    {
        strncpy(t, s, m);
        t[m] = '\0';
        if (atoll(t) < k)
            t[m] = s[m], t[m + 1] = '\0';
        l = strlen(t) - 1;
        for (int i = atoll(t) % k; i; --l, i /= 10)
            s[l] = i % 10 + '0';
        s += l + 1, n -= l + 1;
    }
    fprintf(q, "%d", (int)(atoll(s) % k));
    return 0;
}
