#include <stdio.h>
#include <string.h>

void getstring(FILE *f, char *a)
{
	char s[256];

	fscanf(f, "%s", s);
	strcpy(a + 255 - strlen(s), s);
	for (int i = 0; !a[i]; ++i)
		a[i] = '0';
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char a[256] = {0}, b[256] = {0}, *s;

	getstring(f, a);
	getstring(f, b);
	for (int i = 0; i < 256; ++i)
		if (b[i] == '1' && ++a[i])
		{
			while ((s = strchr(a, '2')))
			{
				*s = '0', ++*(s - 1);
				if (s - a == 253)
					++*(s + 1);
				else if (s - a < 253)
					++*(s + 2);
				while ((s = strstr(a, "011")))
					strncpy(s, "100", 3);
			}
			while ((s = strstr(a, "011")))
					strncpy(s, "100", 3);
		}
	fprintf(q, strchr(a, '1'));
	return 0;
}
