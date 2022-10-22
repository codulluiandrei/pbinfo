#include <bits/stdc++.h>
using namespace std;
ifstream in("porumb.in");
ofstream out("porumb.out");
#define cin in
#define cout out
int n, temp, contor = 0;
int main() {
    cin >> n >> temp;
    cout << (n + 1) / 2 << "\n";
    int copie = n;
    while (copie > 0) {
        copie = copie / 2;
        contor++;
    } cout << contor << "\n";
    while (temp % 2 == 0) {
        copie++;
        temp = temp / 2;
    } cout << copie + 1 << "\n";
    copie = 1;
    while (copie * 2 <= n)
        copie = copie * 2;
    cout << copie;
    return 0;
}