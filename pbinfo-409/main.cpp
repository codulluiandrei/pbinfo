#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, contor = 0; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int temp; cin >> temp;
		int copie = temp, ogl = 0;
		while (temp) {
			int cif = temp % 10;
			ogl = ogl * 10 + cif;
			temp = temp / 10;
		} int a = ogl, b = copie;
		while (b) {
			int r = a % b;
			a = b;
			b = r;
		} if (a == 1) contor++;
	} cout << contor;
	return 0;
}
