#include <iostream>
using namespace std;
int main() {
    int n, v[26], x, j;
    cin >> n >> x >> j;
    for (int i = 1; i <= n; i++)
            cin >> v[i];
    n++;
    for (int i = n; i > j; i--)
            v[i] = v[i - 1];
    v[j] = x;
    for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
    return 0;
}
