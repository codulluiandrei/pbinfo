#include <bits/stdc++.h>
using namespace std;
int main() {
    int v[300];
    int k = 1;
    for(int i = 10; i <= 99; i++) {
        v[k] = i / 10;
        k++;
        v[k] = i % 10;
        k++;
    } k--;
    int temp; cin >> temp;
    cout << v[temp];
    return 0;
}
