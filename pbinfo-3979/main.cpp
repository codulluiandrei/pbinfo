#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n, S = 0;
	cin >> n;
	while (n) {
		int temp = n % 10;
		if (temp > 2 && temp < 8) S = S + temp;
		n = n / 10;
	} cout << S;
	return 0;
}