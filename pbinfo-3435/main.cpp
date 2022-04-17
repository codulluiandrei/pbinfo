#include <bits/stdc++.h>
using namespace std;
string problema = "foto";
ifstream in(problema + ".in");
ofstream out(problema + ".out");
#define cin in
#define cout out
int mat[101][101];
int C, N, M;
void cerinta1(), cerinta2();
int main() {
    cin >> C >> N >> M;
    if (C == 1) cerinta1();
    else cerinta2();
    return 0;
}
void cerinta1() {
    int temp, P = 0;
    for (int i = 1; i <= N; ++i) {
        int p = 0;
        for (int j = 1; j <= M; ++j) {
            cin >> temp;
            if (temp == 0) p++;
            else {
                P = max(p, P);
                p = 0;
            } P = max(p, P);
        }
    } out << P << "\n";
}
void cerinta2() {
    int H = 0, F = 0, temp;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                temp = mat[i - 1][j - 1] + mat[i - 1][j] + mat[i - 1][j + 1];
                if (temp == 0) F++;
                mat[i][j] = 1 + temp;
                H = max(mat[i][j], H);
            }
        } out << F << " " << H << "\n";
}