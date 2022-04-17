#include <iostream>
using namespace std;
int main() {
    int n, v[100];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int j = n; j >= 1; j--)
        if (v[j] % 2 == 0) {
            for (int i = n; i >= j; i--)
                v[i + 1] = v[i];
            n++;
            v[j + 1] = 2 * v[j];
        }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}
