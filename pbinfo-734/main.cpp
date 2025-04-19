#include <stdio.h>
#define DIM 50010
long long S[DIM];
long long N, M, i, p, u, m, x;
int main(){
	FILE *f = fopen("miere.in","r");
	FILE *g = fopen("miere.out","w");
	fscanf(f,"%lld",&N);
	for (i=1, S[0] = 0;i<=N;i++){
		fscanf(f,"%lld",&x);
		S[i] = S[i-1] + x;
	}
	fscanf(f,"%lld",&M);
	for (i=0;i<M;i++) {
		fscanf(f,"%lld",&x);
		p = 1; u = N;
		while (p<=u) {
			m = (p+u)/2;
			if (S[m]+i*m <= x)
				p = m+1;
			else
				u = m-1;
		}
		if (S[u]<=x)
			fprintf(g,"%lld\n",u);
		else
			fprintf(g,"%lld\n",p);
	}
	fclose(f);
	fclose(g);
	return 0;
}