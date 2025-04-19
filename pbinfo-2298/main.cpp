#include <stdio.h>
long long N, K;
long long cif[20], l;
int main() {
	freopen("magnitudine.in", "rt", stdin);
	freopen("magnitudine.out", "wt", stdout);
	scanf("%lld %lld", &N, &K);
	while (N) {
		cif[l++] = N % 10;
		N /= 10;
	}
	int rez = 9;
	for (int elimin1 = 0; elimin1 < l; elimin1++) {
		for (int elimin2 = 0; elimin2 < l; elimin2++) {
			int min = 9, max = 0;
			for (int i = 0; i < l; i++) {
				if (K == 0 || // nu evit nimic
					(K == 1 && i != elimin1) || // evit orice pozitie
					(K == 2 && i != elimin1 && i != elimin2)) { // evit orice doua pozitii
					if (min > cif[i]) {
						min = cif[i];
					}
					if (max < cif[i]) {
						max = cif[i];
					}
				}
			}
			if (rez > max - min) {
				rez = max - min;
			}
		}
	}
	printf("%lld\n", rez);	
	fclose(stdout);
	return 0;
}