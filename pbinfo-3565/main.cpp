/*
	Problema Furnici
	Complexitate timp O(N)
	Complexitate spatiu O(1)
sursa 100 p - Robert Hasna
*/
#include <cstdio>
using namespace std;
int L, N, rez, x;
char dir;
inline int max(int x, int y) { return x > y ? x : y; }
int main() {
	freopen("furnici1.in", "r", stdin);
	freopen("furnici1.out", "w", stdout);
	scanf("%d %d\n", &L, &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %c\n", &x, &dir);
		if (dir == 'S') rez = max(rez, x);
		else rez = max(rez, L - x);
	}
	printf("%d\n", rez);
	return 0;
}