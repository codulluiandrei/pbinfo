/*
Complexitate timp: O(PlogP)
100 puncte
*/
#include <stdio.h>
#include <stdlib.h>
#define PMax 100005
FILE *fin = fopen("piscina.in", "rt");
FILE *fout = fopen("piscina.out", "wt");
int n, m, p;
typedef struct point {
	int x, y;
} point;
point c[PMax];
int compY(const void *a, const void *b);
long long detMax() {
	qsort(c, p, sizeof(c[0]), compY);
	int prev = 0;
	long long aMax = 0, area;
	for (int i = 1; i < p; i++) {
		if (c[i].x < c[prev].x) {
			area = c[prev].x;
			area *= c[i].y;
			prev = i;
			if (aMax < area) {
				aMax = area;
			}
		}
	}
	return aMax;
}
int compY(const void *a, const void *b) {
	return ((point *) a) -> y - ((point *) b) -> y;
}
void mirror(point *c, int N, int M) {
	for (int i = 0; i < p; i++) if (c[i].x && c[i].y) {
		if (N > 0) {
			c[i].x = N - c[i].x;
		}
		if (M > 0) {
			c[i].y = M - c[i].y;
		}
	}
}
int main() {
	fscanf(fin, "%d %d %d", &n, &m, &p);
	for (int i = 0; i < p; i++) {
		fscanf(fin, "%d %d", &c[i].x, &c[i].y);
	}
	c[p].x = 0; c[p].y = m;
	c[p + 1].x = n; c[p + 1].y = 0;
	p += 2;
	long long aMax = 0, area;
	area = detMax(); if (aMax < area) { aMax = area; }
	mirror(c, n, 0);
	area = detMax(); if (aMax < area) { aMax = area; }
	mirror(c, 0, m);
	area = detMax(); if (aMax < area) { aMax = area; }
	mirror(c, n, 0);
	area = detMax(); if (aMax < area) { aMax = area; }
	fprintf(fout, "%lld\n", aMax);
	fclose(fin);
	fclose(fout);
	return 0;
}