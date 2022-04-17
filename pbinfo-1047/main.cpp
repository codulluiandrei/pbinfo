#include <bits/stdc++.h>
using namespace std;
ifstream in("patrat2.in");
ofstream out("patrat2.out");
int adi[] = {-1, 1, -1, 1, 0, 0, 1, -1};
int adj[] = { 1, -1, -1, 1, 1, -1, 0, 0};
int mat[300][300], n, m;
int maxim, stele, patrate;
int main() {
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int adv = 1;
            for (int q = 0; q <= 7; q++)
                if (mat[i + adi[q]][j + adj[q]] >= mat[i][j]) adv = 0;
            stele = stele + adv;
            if (adv == 1) mat[i][j] = 10001;
        }
    for (int i = 1; i < n; i++)
        for (int j= i + 1; j <= n; j++) {
            int temp = j - i;
            for (int q = 1; q + temp <= m; q++)
                if (mat[i][q] == 10001 && mat[i][q + temp] == 10001 && mat[j][q] == 10001 && mat[j][q + temp] == 10001) {
                    patrate++;
                    if (temp > maxim) maxim = temp;
                }
        }
    out << stele << "\n" << patrate << "\n" << maxim + 1;
    return 0;
}