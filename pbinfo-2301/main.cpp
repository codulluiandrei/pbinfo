#include <cstdio>
#define MAXN 1000001

using namespace std;

int A[MAXN], B[MAXN], N, K, S, P, i;

void solve1() {
	int ul = 0, Nr = 0, i;

	for (i = 1; i <= N; ++i) {
		B[ul + 1] = B[ul] + A[i]; //sume partiale
		++ul;
		if (ul >= K && B[ul] - B[ul - K] > S) {
			++Nr;
			ul -= K;
		}
	}
	printf("%d\n", Nr);
}

void solve2() {
	int ul = 0, i;

	for (i = 1; i <= N; ++i) {
		B[ul + 1] = B[ul] + A[i];
		++ul;
		if (ul >= K && B[ul] - B[ul - K] > S) {
			printf("%d ", ul - K + 1);
			ul -= K;
		}
	}
}

void solve3() {
	int pr = 1, ul = 0, Nr = 0, i;

	for (i = 1; i <= N; ++i)
		A[i] += A[i - 1];

	for (i = 1; i <= N; ++i) {
		if (i + K <= N) {
			while (pr <= ul && A[i + K] - A[i - 1] >= A[B[ul] + K] - A[B[ul] - 1])
				--ul;
			B[++ul] = i;
		}
		if (A[B[pr] + K] - A[B[pr] - 1] - (A[i] - A[i - 1]) > S)
			++Nr;
		if (B[pr] == i - K)
			++pr;
	}
	printf("%d", Nr);
}

int main()
{
	freopen("secv.in", "r", stdin);
	freopen("secv.out", "w", stdout);

	scanf("%d", &P);
	scanf("%d %d %d", &N, &K, &S);
	for (i = 1; i <= N; ++i)
		scanf("%d", &A[i]);

	if (P == 1) solve1();
	if (P == 2) solve3();

	return 0;
}
