#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, temp;
    cin >> n >> m;
    temp = m * n;
    while (temp != 0) {
        int val = m;
        for (int i = temp; val != 0; i--) {
            cout << i << " ";
            val--;
        } temp = temp - m;
        cout << endl;
    } return 0;
}