#include <iostream>
using namespace std;
int main () {
    int n, D = 0, nrp = 0, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[0] = v[1];
        if (v[i] - v[i - 1] < 0) {
            if (v[i - 1] - v[i] > D)
            D = v[i - 1] - v[i];
        } else {
            if (v[i] - v[i - 1] > D)
            D = v[i] - v[i - 1];
        }
    } for (int i = 1; i <= n; i++) {
        if (v[i] - v[i - 1] < 0) {
            if (v[i - 1] - v[i] == D)
            nrp++;
        } else {
            if (v[i] - v[i - 1] == D)
            nrp++;
        }
    } cout << D << " " << nrp;
}
