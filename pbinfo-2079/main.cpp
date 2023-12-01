#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 9001
#define MAXDIV 770

int N, NR, A[MAXN], st[MAXN], pos[MAXN], sol[MAXDIV];
long steps = 0;

int check(int K)
{
	int i, j, t = 1, p = 0, val = 0;

	for(i = 1; i <= N; i++)
	{
		steps++;
		while(t <= p && pos[t] <= i-K) val -= st[t++];
		if(A[i] < val || (i > N-K+1 && A[i] != val)) return 0;
		if(A[i] > val) pos[++p] = i, st[p] = A[i]-val, val = A[i];
	}

	return 1;
}

void read_and_solve(void)
{
	int i, j, k; long d = 0;

	scanf("%d\n", &N), NR = 0;
	assert(N >= 1 && N <= 9000);

	for(i = 1; i <= N; i++) scanf("%d ", &A[i]), d += (long)A[i],
	assert(A[i] >= 0 && A[i] <= 10000);

	for(i = 1; i <= N; i++)
	 if(d % i == 0 && check(i)) sol[++NR] = i;

	for(i = 1; i <= NR; i++)
	 for(j = i+1; j <= NR; j++)
		if(sol[i] > sol[j]) k = sol[i], sol[i] = sol[j], sol[j] = k;

	for(i = 1; i <= NR; i++) printf("%d ", sol[i]);
	printf("\n");
}

int main(void)
{
	int teste, start, end;

	freopen("auto.in", "rt", stdin);
	freopen("auto.out", "wt", stdout);

	start = clock();

	scanf("%d ", &teste);
	while(teste--)
		read_and_solve();

	fprintf(stderr, "%ld\n", steps);

	end = clock();

	fprintf(stderr, "%lf\n", (double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}
