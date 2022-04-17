#include <iostream>
using namespace std;
int main() {
	int v[101], n, copie[101], Spar = 0, Sppar = 0, nrdiv = 0, Simp = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	int temp = n;
	for (int i = 1; i <= n; ++i) {
		copie[i] = v[temp];
		temp--;
	} for (int i = 1; i <= n; ++i) {
		cout << copie[i] << " ";
	} cout << "\n";
	for (int i = 1; i <= n; ++i) {
		if (v[i] % 2 == 0) Spar = Spar + v[i];
		if (i % 2 == 0) Sppar = Sppar + v[i];
		if (v[i] % 10 == 0) nrdiv++;
		if (i % 2 != 0 && v[i] % 3 == 0) Simp = Simp + v[i];
	} cout << Spar << "\n";
	cout << Sppar << "\n";
	cout << nrdiv << "\n";
	cout << Simp << "\n";
	return 0;
}
