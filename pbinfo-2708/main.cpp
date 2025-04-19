#include <iostream>
using namespace std;
long long int n, temp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> temp; if (temp % 2 == 0) cout << 0 << " ";
		else cout << 1 << " ";
	} return 0;
}