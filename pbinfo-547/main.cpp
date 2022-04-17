#include <iostream>
using namespace std;
int main() {
	int n, maxim = -1, minim = 9999999, var, temp = 0, v[100001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		if (v[i] < minim) minim = v[i];
		else if (v[i] > maxim) maxim = v[i];
		var = maxim - minim;
	} var = maxim - minim;
	for (int i = 1; i <= n; i++)
		if (var == v[i]) temp++;
	cout << temp;
}