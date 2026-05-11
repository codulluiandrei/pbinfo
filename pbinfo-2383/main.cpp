#include <cstdio>
#define NMax 2004
using namespace std;
int M, N, A, B, U, X[128], Y[128];
int S[NMax][NMax], Res;
int main()
{
	int i, j, x1, y1, x2, y2;
	bool ok = false;
	freopen("plaja1.in", "r", stdin);
	freopen("plaja1.out", "w", stdout);
	scanf("%d %d %d", &A, &B, &U);
	for (i = 1; i <= U; ++i)
		scanf("%d %d", &X[i], &Y[i]);
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (j = 1, ok = true; j <= U && ok; ++j)
			if (x1 <= X[j] && X[j] <= x2 && y1 <= Y[j] && Y[j] <= y2)
				ok = false;
		if (!ok)
			continue;
		++Res;
		++S[x1][y1];
		++S[x2+1][y2+1];
		--S[x1][y2+1];
		--S[x2+1][y1];
	}
	printf("%d ", Res);
	for (i = 1; i <= A; ++i)
		for (j = 1; j <= B; ++j)
			S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
	for (i = 1; i <= U; ++i)
		S[X[i]][Y[i]] = 1;
	for (i = 1; i <= A; ++i)
		for (j = 1; j <= B; ++j)
			S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (S[i][j] != 0);
	Res = 0;
	for (scanf("%d", &M); M; --M)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		Res += (S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1] == 0);
	}
	printf("%d\n", Res);
	return 0;
}