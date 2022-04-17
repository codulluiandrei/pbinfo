#include <iostream>
using namespace std;
int main() {
	int n, div = 0; cin >> n;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            if (i % 2 == 0)
                div++;
            if (i * i != n && ((n / i) % 2 == 0))
                div++;
        }
    cout << div;
    return 0;
}
