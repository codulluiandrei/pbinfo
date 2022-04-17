#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull diagonale(ull n) {
    return n * (n - 3) / 2;
}
ull suma(ull n) {
    return 180 * (n - 2);
}
ull n;
int main() {
    cin >> n;
    cout << diagonale(n) << "\n";
	cout << suma(n);
	return 0;
}