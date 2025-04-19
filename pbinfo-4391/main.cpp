#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 100000;
int N;
int A[N_MAX + 2];
int B[N_MAX + 2];
int C[N_MAX + 2];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}
	C[0] = 1;
	for (int i = 1; i <= N; i++) {
		C[i] = max(C[i - 1], A[i]);
		if (C[i] > B[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";
	return 0;
}