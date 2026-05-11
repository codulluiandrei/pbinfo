/*
autor:   Paul Diac
timp:    O(N*M*logN)
memorie: O(N+M)
idee:    generez un APM cu algoritmul Kruskal, apoi elimin temporar cate o muchie din el si re-calculez APM.
         folosind union-find cu compactarea drumurilor. Atentie: raspunsul e posibil mai mare ca 2^32.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <cassert>
#include <vector>
#include <set>
using namespace std;
#define NMax 1000005
int N, M, c;
typedef struct edge {
	int x, y, c;
	bool inFirstMST, banned;
} edge;
edge e[NMax];
int p[NMax]; // parintele din componenta conexa (union-find).
int i, np, a[NMax];
int find(int x) {
	for (np = 0, i = x; p[i] != i; i = p[i]) { a[np++] = i; }	
	for (int j = 0; j < np; j++) { p[a[j]] = i; } // compactarea drumului
	return i;
}
void union_(int x, int y) { p[find(x)] = find(y); }
int cmpCost(const void * a, const void * b) { return ((edge*)a)->c - ((edge*)b)->c; }
// Kruskal - O(MlogN)
long long findMST(bool addToFirst) {
	if (addToFirst) { qsort(e, M, sizeof(e[0]), cmpCost); }
	for (int i = 1; i <= N; i++) { p[i] = i; }
	int ei = 0; int NN = N-1; long long cMin = 0;
	while (NN--) {
		for (; ei < M && (find(e[ei].x) == find(e[ei].y) || e[ei].banned); ei++);
		if (ei < M) {
			union_(e[ei].x, e[ei].y);
			if (addToFirst) { e[ei].inFirstMST = true; }
			cMin += e[ei].c;
		}
	}
	return cMin;
}
int main() {
    freopen("esentiale.in", "rt", stdin);
	freopen("esentiale.out", "wt", stdout);
	scanf("%ld %ld %ld", &N, &M, &c);
	for (int i = 0; i < M; i++) {
		scanf("%d %ld %ld", &e[i].x, &e[i].y, &e[i].c);
		e[i].inFirstMST = false;
	}
	long long ccMin = findMST(true);
	if (c == 1) { printf("%lld\n", ccMin); }
	else {
		int essential = 0;
		for (int i = 0; i < M; i++) if (e[i].inFirstMST) {
			e[i].banned = true;
			if (ccMin != findMST(false)) { essential++; }
			e[i].banned = false;
		}
		printf("%ld\n", essential);
	}
	fclose(stdout);
	return 0;
}