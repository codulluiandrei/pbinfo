#include <iostream>
using namespace std;
int v[105], n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) {
                int temp; cin >> temp;
                v[j] = v[j] + temp;
            }
    int maxim = 1;
    for (int  i = 2; i <= n; ++i)
        if (v[i] > v[maxim])
            maxim = i;
    cout << maxim;
    return 0;
}