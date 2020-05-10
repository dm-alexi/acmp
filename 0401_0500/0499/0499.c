#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a1, a2, a3, b1, b2, b3, k, w;

	fscanf(f, "%d%d%d%d%d%d%d%d", &k, &w, &a1, &b1, &a2, &b2, &a3, &b3);
	fprintf(q, (a1 <= w && b1 >= k) || (a2 <= w && b2 >= k) || (a3 <= w && b3 >= k) || (a1 + a2 + a3 <= w && b1 + b2 + b3 >= k) ||
		(a1 + a2 <= w && b1 + b2 >= k) || (a1 + a3 <= w && b1 + b3 >= k) || (a2 + a3 <= w && b2 + b3 >= k) ? "YES" : "NO");
	return 0;
}
