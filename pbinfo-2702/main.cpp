#include <bits/stdc++.h>
using namespace std;
int freq[1001], contor = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        freq[temp]++;
    }
    for (int i = 1; i <= 100; i++) {
        contor = contor + floor(freq[i] / 2);
    }
    cout << contor;
}
