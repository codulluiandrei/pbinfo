#include <bits/stdc++.h>
using namespace std;
ifstream in("mincols1.in");
ofstream out("mincols1.out");
#define cin in
#define cout out
int mat[33][33], n, rez = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            in >> mat[i][j];
    bool adv = false;
    for (int j = 1; j <= n; ++j) {
        int minim = mat[1][j];
        for (int i = 2; i <= n; ++i)
            if (mat[i][j] < minim)
                minim = mat[i][j];
		if (minim == mat[n - j + 1][j]) {
            rez = (rez * minim) % 10; 
            adv = true;
        }
    } if (adv)
        cout << rez;
    else
        cout << "NU EXISTA";
    return 0;
}