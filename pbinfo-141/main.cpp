
//100p
#include <stdio.h>
#include <string.h>
#define DIM 100010

int C[DIM];
int P[DIM];
int Q[DIM];
int V[DIM];
int N, Vmax, i, j, p, q, D;


int main() {
	FILE *f = fopen("compuneri.in","r");
	fscanf(f,"%d",&N);
	for (i=1;i<=N;i++) {
		fscanf(f,"%d",&V[i]);
		if (V[i]>Vmax)
			Vmax = V[i];
	}
	fclose(f);

	for (i=2;i<=Vmax;i++)
		if (C[i] == 0) {
			for (j=i+i;j<=Vmax;j+=i)
				C[j] = 1;

		}

	for (i=1;i<=N;i++)
		if (!C[V[i]])
			P[++p] = V[i];
		else
			Q[++q] = V[i];

	memset(C, 0, sizeof(C));
	for (i=1;i<=p;i++) {
		C[P[i]] = 1;
		for (j=P[i]+P[i];j<=Vmax; j+=P[i])
			C[j] = 1;
	}
	for (i=1;i<=q;i++)
		if (C[Q[i]] == 0)
			D++;
	FILE *g = fopen("compuneri.out","w");
	fprintf(g,"%d %d",p,D);
	fclose(g);
	return 0;
}
