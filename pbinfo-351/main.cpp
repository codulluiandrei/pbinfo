#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp = 1;
    cin >> n;
    while (temp <= n) {
        for (int i = 1; i <= temp; i++)
            cout << i << " ";
        cout << endl;
        temp++;
    }
    return 0;
}