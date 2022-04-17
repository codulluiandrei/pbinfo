#include <iostream>
using namespace std;
int main() {
	int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int j = n; j >= 1; j--)
        if (v[j] % 2 == 0 ) {
            for (int i = j; i < n; i++)
                v[i] = v[i + 1];
            n--;
        }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}
