#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int A0[MAXN], A1[MAXN], B[MAXN];
int n;
int transform(int A[]) {
	int ops = 0;
	for(int i = 1; i < n; ++i) {
		if(A[i] != B[i]) {
			A[i] ^= 1;
			A[i + 1] ^= 1;
			A[i + 2] ^= 1;
			ops += 1;
		}
	}
	return ops;
}
int main() {
  freopen("leduri.in", "r", stdin);
  freopen("leduri.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> A0[i];
		A1[i] = A0[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> B[i];
	}
	A1[1] ^= 1; A1[2] ^= 1;
	int a = transform(A0);
	int b = transform(A1);
	int ans = 1000000;
	if(A0[n] == B[n]) ans = min(ans, a);
	if(A1[n] == B[n]) ans = min(ans, b + 1);
  if(ans == 1000000)
    ans = -1;
	cout << ans << endl;
	return 0;
}