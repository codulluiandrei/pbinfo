#include <iostream>
using namespace std;
int main() {
	long long int S = 0, n, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a >> b;
        if (a > b) S = S + a;
        else S = S + b;
    } cout << S;
    return 0;
}
