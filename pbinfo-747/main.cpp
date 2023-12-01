#include <stdio.h>
#define DIM 110

long V[DIM];
long n,m,k,d,c,i,max,poz,cost,pas,rez;

int main() {
	FILE *f = fopen("turism.in","r");
	fscanf(f,"%ld%ld%ld",&n, &k, &m);
	for (pas=1;pas<=m;pas++) {
		for (i=1;i<=k;i++)	
			if (V[i])
				V[i]--;
			
		fscanf(f,"%ld",&d);
		poz = 1;
		for (i=1;i<=d;i++) {
			fscanf(f,"%ld",&c);
			while (poz<=k && V[poz])
				poz++;
			if (poz<=k) {
				V[poz] = c;
				cost += c;
			}
		}
	}
	max = V[1];
	for (i=2;i<=k;i++)
		if (V[i]>max)
			max = V[i];
	fclose(f);
	
	rez = (m-1)/n+1;
	if (max)
		rez+=((max-m%n-1)/n+1);
//		rez+=((max-1)/n+1);
	
	FILE *g = fopen("turism.out","w");
	fprintf(g,"%ld %ld",cost,rez);
	fclose(f);
	
	return 0;
}


