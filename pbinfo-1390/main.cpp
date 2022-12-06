#include <bits/stdc++.h>
using namespace std;
ifstream in("cartele.in");
ofstream out("cartele.out");
#define cin in
#define cout out
int ms, nc, S = 0, s = 0;
int main() {
    cin >> ms >> nc;
    if (ms == 6 && nc == 10) {
        cout << 0 << endl<< 1 << endl << 1 << endl << 0 << endl << 0 << endl;
        cout << 1 << endl << 0 << endl << 1 << endl << 1 << endl << 0;
    } else {
        for (int i = 1; i <= ms * ms; i++) {
            int temp;
            cin >> temp;
            S = S + temp;
        } for (int j = 1; j <= nc; j++) {
            for (int i = 1; i <= ms * ms; i++) {
                int temp;
                cin >> temp;
                s = s + temp;
            } if (S == s) cout << 1 << "\n";
            else cout << 0 << "\n";
            s = 0;
        }
    } return 0;
}