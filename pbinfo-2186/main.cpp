//Paul Diac 100
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>
#define NMax 1000000
using namespace std;
int T = 10;
int N, C, B;
int v[NMax];
struct man {
	int w, prev, next, barked;
};
man o[NMax];
int compDesc(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}
int validTogether(int i, int j) {
	return (0 <= i && i < N && 0 <= j && j < N && o[i].barked == 0 && o[j].barked == 0 &&
		i < j && o[i].w + o[j].w <= C && o[i].w - o[j].w <= B && o[j].w - o[i].w <= B);
}
void remove(int &idx) {
	o[idx].barked = 1;
	o[o[idx].prev].next = o[idx].next;
	o[o[idx].next].prev = o[idx].prev;
	idx = o[idx].next;
}
int main() {
	string fname = "barci";
	FILE *fin = fopen((fname + ".in").c_str(), "rt");	
	FILE *fout = fopen((fname + ".out").c_str(), "wt");
	fscanf(fin, "%d %d %d", &N, &C, &B);
	assert(N <= 100000);
	assert(C <= 1000000000);
	assert(B <= 1000000000);
	assert(1 <= N);
	assert(1 <= C);
	assert(0 <= B);
	for (int i = 0; i < N; i++) {
		fscanf(fin, "%d", &v[i]);
		assert(v[i] <= v[i]);
		assert(1 <= v[i]);
	}
	qsort(v, N, sizeof(v[0]), compDesc);
	for (int i = 0; i < N; i++) {
		o[i].w = v[i];
		o[i].next = i+1;
		o[i].prev = i-1;
		o[i].barked = 0;
	}
	o[N].prev = N-1;
	int left;
	for (left = N-1; left >= 0 && o[0].w + o[left].w <= C; left--);
	left++; // left end of interval with valid pair of current man
	int boats = 0;
	for (int i = 0; i < N; i++) if (!o[i].barked) {
		if (left == i) {
			left = o[left].next;
		}
		// left is always on the right (and smaller than) i.
		// and all left of i are barked
		while (o[left].prev > i && o[i].w + o[o[left].prev].w <= C) {
			left = o[left].prev;
		}
		if (validTogether(i, left)) {
			//fprintf(fout, "%d %d\n", o[i].w, o[left].w);
			remove(left);
		}
		o[i].barked = 1;
		boats++;
	}
	fprintf(fout, "%d\n", boats);
	fclose(fin);
	fclose(fout);
	return 0;
}