#include <bits/stdc++.h>
using namespace std;
ifstream in("criptare.in");
ofstream out("criptare.out");
int n, c, L[1001], C[1001], kL, kC;
bool a[1001][1001], S_lin[1001], S_col[1001];
int main() {
    in >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
        in >> a[i][j];
        if (a[i][j]) S_lin[i] = S_col[j]=1;
    } for (int i = 1; i <= n; i++) {
        if (S_lin[i] == 0) L[++kL]=i;
        if (S_col[i] == 0) C[++kC]=i;
    } out << max(kL, kC) << '\n';
    int minim = min(kC, kL);
    for (int i = 1; i <= minim; i++) { 
        out << L[i] << " " << C[i] << '\n';}
    if (kL > kC)
        for (int i = minim + 1; i <= kL; i++) {
        out << L[i] << " " << 1 << '\n';}
    else for (int i = minim + 1; i <= kC; i++) {
        out << 1 << " " << C[i] << '\n';}
    return 0;
}
