#include <bits/stdc++.h>
using namespace std;
string prob = "sumaxl";
ifstream in(prob + ".in");
ofstream out(prob + ".out");
#define cin in
#define cout out
int mare[10001], mic[1001];
int nr1, nr2, temp, var = 0, nrcif = 1, cif;
int main() {
    cin >> nr1;
    for(int i = nr1; i >= 1; i--) cin >> mare[i];
    cin >> nr2;
    while (nr2 != 0) {
        mic[nrcif++] = nr2 % 10;
        nr2 = nr2 / 10;
    } nrcif--;
    if (nrcif > nr1) nr1 = nrcif;
    for (int i = 1; i <= nr1; i++) {
        int c = mare[i] + mic[i] + var;
        mare[i] = c % 10;
        var = c / 10;
    } if (var > 0) mare[++nr1] = var;
    for (int i = nr1; i >= 1; i--) cout << mare[i];
    return 0;
}
