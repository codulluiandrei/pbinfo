#include <iostream>
using namespace std;
int main() {
    int n, v[222], t[222];
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int S = 0;
    for (int i = 0; i < n; ++i)
        S = S + v[i];
    for (int i = 0; i < n; ++i)
        t[i] = S - v[i];
    for (int i = 0; i < n; ++i)
        cout << t[i] << " ";
    return 0;
}