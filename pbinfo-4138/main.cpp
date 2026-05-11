#include <stdio.h>
/*
autor        Paul Diac
idee         iteram toate inaltimile, retinem o varfurile in ordine scrict descrescatoare si cele mai adanci vai de dupa ele
             un varf nou adaugat elimina toate varfurile mai mici decat el, deci vom folosi o stiva pentru varfuri in ordine
			 pentru a evita alte cazuri, la inceput calculam proeminenta la stanga, si apoi la dreapta dupa o oglindire
			 la final afisam minimul dintre cele doua proeminente calculate
memory       O(N)
time         O(N)
score        100
*/
#include <stdio.h>
#define NMax 1000005
long N, C, s;
long a[NMax];
long min_(long i, long j) { if (i < j) return i; return j; }
long peak[NMax], valley[NMax], top = -1; // stiva de varfuri "peak" si cele mai adanci vai "valley"
long prom[2][NMax]; // proeminenta la stanga varfului de pe pozita i este prom[0][i], si la dreapta este prom[0][n-1-i] datorita oglindirii
void popTop() { // eliminam un varf din stiva, actualizam cea mai adanca vale din dreapta daca e cazul
	if (top < 0) { return; }
	if (top >= 1 && valley[top-1] > valley[top]) {
		valley[top-1] = valley[top];
	}
	top--;
}
int main() {
	freopen("proeminenta.in", "r", stdin);
	freopen("proeminenta.out", "w", stdout);
	scanf("%ld %ld", &C, &N);
	for (int i = 0; i < N; i++) {
		scanf("%ld", &a[i]);
		if (i > 0 && a[i] == a[i-1]) {
			i--; N--; // eliminam duplicatele
		}
	}
	if (C == 1) {
		for (int i = 1; i < N-1; i++) {
			if (a[i-1] < a[i] && a[i] > a[i+1]) { s++; } // este varf
		}
		printf("%ld\n", s);
		return 0;
	}
	for (int d = 0; d <= 1; d++) { // d=0 va fi parcurgerea stanga-dreapta, si la d=1 dupa oglindire, adica dreapta-stanga
		for (int i = 1; i < N-1; i++) {
			if (a[i-1] < a[i] && a[i] > a[i+1]) { // este varf
				prom[d][i] = a[i];
				while (top >= 0 && a[peak[top]] <= a[i]) { // elimim varfurile mai mici din stiva pe rand
					popTop();
				}
				if (top >= 0 && a[peak[top]] > a[i]) { prom[d][i] = a[i] - valley[top]; } // am gasit primul varf mai mare din stanga
				peak[++top] = i;
				valley[top] = a[i]; // adaugam noul varf
			}
			if (top >= 0 && valley[top] > a[i]) { valley[top] = a[i]; }
		}
		for (int i = 0; i < N / 2; i++) { // oglindim altitudinile
			long aux = a[i]; a[i] = a[N-1-i]; a[N-1-i] = aux;
		}
		top = -1;
	}
	for (int i = 1; i < N-1; i++) if (a[i-1] < a[i] && a[i] > a[i+1]) {
		if (prom[0][i] > prom[1][N-1-i]) { // retinem maximul in prom[0][i]
			prom[0][i] = prom[1][N-1-i];
		}
	}
	for (int i = 1; i < N-1; i++) {
		if (prom[0][i] > 0) { printf("%ld ", prom[0][i]); } // si il afisam
	}
	printf("\n");
	fclose(stdout);
	return 0;
}