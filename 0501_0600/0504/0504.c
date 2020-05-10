#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k;

	fscanf(f, "%d", &k);
	fprintf(q, k % 3 == 0 ? "GCV" : k % 3 == 1 ? "VGC" : "CVG");
	return 0;
}
