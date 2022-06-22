#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, l, se = 2, si = 1;
    cin >> h >> l;
    for(int i = 1; i <= h; i++) {
        for (int j = 1; j <= l; j++) {
            for (int k=1;k<=se;k++)
                cout << "_";
            cout << "0";
            for (int k = 1; k <= si; k++)
                cout << "_";
            cout << "0";
            for (int k = 1; k <= se; k++)
                cout << "_";
            cout << "_";
        } se = (i + 1 != h);
        si = (i + 1 != h) ? 3 : 5;
        cout << endl;
    }
}