#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    char c, d; cin >> c >> d;
    for (int linie = 1; linie <= n; linie++) {
        for (int coloana = 1; coloana <= n; coloana++) {
            if (linie == 1 || linie == n || coloana == 1 || coloana == n)
                cout << c;
            else
                cout << d;
   		} cout << endl;
    }
    return 0;
}