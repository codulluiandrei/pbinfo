//x = 50000 valoarea maxima
//n = 50000 numarul de pro
#include <stdio.h>
#define DIM 50010
#define MOD 2011
struct nod {
	int inf;
	nod *adr;
};
nod *P[DIM],*q;
int D[DIM],t,ta,r,a,i,N,X;
int V[DIM];
int L[DIM];
void df(int k) {
	nod *q = P[k];
	while (q) {
		if (!V[q->inf]) {
			df(q->inf);
		}
		D[k]+=D[q->inf];
		if (L[q->inf] + 1 > L[k] && L[q->inf])
			L[k] = L[q->inf] + 1;
		if (D[k] > MOD)
			D[k]-=MOD;
		q = q->adr;
	}
	V[k] = 1;
}
int main(){
	FILE *f = fopen("progresii.in","r");
	FILE *g = fopen("progresii.out","w");
	fscanf(f,"%d %d",&N, &X);
	for (i=1;i<=N;i++){
		fscanf(f,"%d %d",&a,&r);
//		D[a] = 1;
		ta = a;
		while (ta + r<=X) {
			t = ta+r;
			q = new nod;
			q->inf = ta;
			q->adr = P[t];
			P[t] = q;
			ta = t;
		}
	}
	fclose(f);
	L[0] = 1;
	D[0] = 1;
	df(X);
	fprintf(g,"%d %d",D[X], L[X]);
//	printf("%d %d",D[X],L[X]);
	fclose(g);
	return 0;
}