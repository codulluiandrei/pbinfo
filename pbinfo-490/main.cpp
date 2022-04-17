#include <iostream>
using namespace std;
int main() {
	int v[1001], n, poz_min, poz_max, minim = 100001, maxim = -100001;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i) {
		if (v[i] > maxim) {
			maxim = v[i];
			poz_max = i;
		} else if (v[i] < minim) {
			minim = v[i];
			poz_min = i;
		}
	} if (poz_min > poz_max) {
		int temp = poz_min;
		poz_min = poz_max;
		poz_max = temp;
	} for (int i = poz_min; i <= poz_max; ++i) {
		cout << v[i] << " ";
	} return 0;
}
