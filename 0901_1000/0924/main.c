#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k = 1;
	char s[17];

	fscanf(f, "%s%s%s%s", s, s + 4, s + 8, s + 12);
	for (int i = 0; k && i < 3; ++i)
		for (int j = 0; k && j < 3; ++j)
			if (s[4 * i + j] == s[4 * i + j + 4] && s[4 * i + j] == s[4 * i + j + 1] && s[4 * i + j] == s[4 * i + j + 5])
				k = 0;
	fprintf(q, k ? "Yes" : "No");
	return 0;
}
