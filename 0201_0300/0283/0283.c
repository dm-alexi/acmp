#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int l = 1, ans;
	char s[100001], *t;

	fscanf(f, "%s", s);
	t = s;
	ans = isupper(*t);
	while (*++t && ans)
		if ((isupper(*t) && l < 2) || (islower(*t) && ++l > 4))
			ans = 0;
		else if (isupper(*t))
			l = 1;
	fprintf(q, ans && l > 1 ? "Yes" : "No");
	return 0;
}
