#include <iostream>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 2; i <= n; i = i + 2) cout << v[i] << " ";
    cout << endl;
    if (n % 2 == 0) n--;
    for (int i = n; i > 0; i = i - 2) cout << v[i] << " ";
    return 0;
}