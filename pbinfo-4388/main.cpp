#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	for (int i = 1; i < N / 2; i++) {
		cout << 9;
	}
	cout << 8;
	for (int i = N / 2 + 1; i <= N; i++) {
		cout << 9;
	}
	cout << "\n";
	
	return 0;
}
