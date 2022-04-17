#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, vec[1001]; cin >> n;
    for (int i = 1; i <= n; i++) cin >> vec[i];
    for (int i = 1; i <= n; i++) {
        for (int i2 = i + 1; i2 <= n; i2++) {
            if (vec[i] > vec[i2]) {
                int temp = vec[i];
                vec[i] = vec[i2];
                vec[i2] = temp;
            }
        }
    } for (int i = 1; i <= n; i++)
        cout << vec[i] << " ";
    return 0;
}