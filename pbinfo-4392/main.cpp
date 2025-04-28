/*
 autor Diac Paul
 solutile problema arhitect
 memorie: O(N)
 timp: O(N log N)
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMax 100005
#define llong long long
using namespace std;
typedef struct point {
	long long x, y;
} point;
int N;
point p[2*NMax], p0;
// aria cu semn a triunghiului (0,0)-A-B
llong area00(point A, point B) { return (llong)A.x*B.y-(llong)A.y*B.x; }
// comparator dupa punte ce stabileste ordinea dupa unghiul polar 
int ccw(const void *a, const void *b) {
   llong s = area00(*(point*)a, *(point*)b);
   if (s < 0) return -1;
   else if (s > 0) return 1;
   return 0;
}
int main() {
	freopen("arhitect.in", "r", stdin);
	freopen("arhitect.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		point c[2];
		scanf("%lld %lld %lld %lld", &c[0].x, &c[0].y, &c[1].x, &c[1].y);
		c[1].x -= c[0].x; c[1].y -= c[0].y; p[2*i] = c[1];
		// adaug un segment fictiv perpendicular pe cel original
		p[2*i+1].x = -c[1].y; p[2*i+1].y = c[1].x;
	}
	int max = 0, i, j = 0;
	for (i = 0; i < 2*N; i++) {
		if ((p[i].y < 0) || (p[i].y == 0 && p[i].x < 0)) { p[i].x *= -1; p[i].y *= -1; }
	}
	qsort(p, 2*N, sizeof(p[0]), ccw);
	// dupa sortare determin numarul maxim de segmente cu aceeasi panta in O(N) amortizat
	// indicele j creste fara sa scada
	for (i = 0; i < 2*N; i++) {
		if (j < i) { j = i; }
		while (j < 2*N && (area00(p[i], p[j]) == 0)) { j++; }
		if (max < j - i) {
			max = j - i;
		}
	}
	printf("%d\n", max);
	fclose(stdout);
	return 0;
}