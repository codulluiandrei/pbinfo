#include <iostream>
using namespace std;
int main() {
    int freqv1[10001] = {0}, freqv2[10001] = {0}, n, m, K;
    long long int rez = 0;
    cin >> n >> K;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        freqv1[temp]++;
    } cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        freqv2[temp]++;
    } for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000 && i * j < K; ++j)
            rez = rez + freqv1[i] * freqv2[j];
    } cout << rez;
    return 0;
}