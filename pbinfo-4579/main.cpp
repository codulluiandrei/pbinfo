#include<stdio.h>
#define MOD 2011
int putere(int a, int b) {
	int p, p2;
	p = 1;
	p2 = a%MOD;
	while (b) {
		if (b&1) {
			p = (p*p2)%MOD;
		}
		b>>=1;
		p2 = (p2*p2)%MOD;
	}
	return p;
}
int n,m,k;
int main(){
	FILE *f = fopen("descompunere_prin_reuniune.in","r");
    FILE *g = fopen("descompunere_prin_reuniune.out","w");
	fscanf(f,"%d %d",&n, &m);
	fclose(f);
	k = putere(2,m);
	k--;
	if (k<0)
		k+=MOD;
	k = putere(k,n);
	fprintf(g,"%d",k);
	fclose(g);
	return 0;
}