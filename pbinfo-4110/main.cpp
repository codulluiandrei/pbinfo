#include <bits/stdc++.h>
using namespace std;
int v[1001], n, contor;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp; 
		cin >> temp;
		for (int d = 1; d * d <= temp; d++) {
			if (temp % d == 0)
				v[i] = v[i] + d + temp / d;
			if (d * d == temp)
				v[i] = v[i] - d;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (i != j && v[i] == v[j])
				contor++;
	cout << contor;
	return 0;
}