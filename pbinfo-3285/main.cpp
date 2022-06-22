#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, multime[100001];
    cin >> n;
    int maxim = -1, temp = 0;
    for (int i = 1; i <= n; i++)
        cin >> multime[i];
    for (int i2 = 1; i2 <= n/2; i2++)
        if (multime[i2] > maxim)
            maxim = multime[i2];
    for (int i = n/2 + 1; i <= n; i++)
        if(maxim < multime[i])
            temp++;
    cout << temp;
    return 0;
}