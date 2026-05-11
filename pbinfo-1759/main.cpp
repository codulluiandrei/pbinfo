//Solutia oficiala, Marius Nicoli	100p N log(VMAX) + Q
#include <stdio.h>
#define DIM 100010
#define MAX 2000000000
long long mc;
int m, X, Q, N, i, ok, q, depaseste;
int cmmdc(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int minim (int a, int b) {
	return a < b ? a : b;
}
int main() {
	FILE *f = fopen("alune.in","r");
	FILE *g = fopen("alune.out","w");
	fscanf(f,"%d %d",&N, &Q);
	fscanf(f,"%d",&X);
	mc = m = X;
	depaseste = 0;
	for (i = 2; i<=N; i++) {
		fscanf(f,"%d",&X);
		m = minim(m, X);
		if (depaseste)
			continue;		
		mc = mc / cmmdc(mc, X) * X;
		if (mc > MAX) {
			depaseste = 1;
		}
	}
	for (;Q;--Q) {
		ok = 1;
		fscanf(f,"%d",&q);
		if (depaseste) {
			if (q >= m) {
				ok = 0;
			}
		} else {
			if (q % mc >= m) {
				ok = 0;
			}
		}
		fprintf(g,"%d",ok);
	}
	fprintf(g,"\n");
	fclose(g);
	fclose(f);
	return 0;
}