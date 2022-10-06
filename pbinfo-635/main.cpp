#include <bits/stdc++.h>
using namespace std;
ifstream in("vecini1.in");
ofstream out("vecini1.out");
#define cin in
#define cout out
int dlin[] = {0, 0, 1, -1}, dcol[] = {1, -1, 0, 0};
long long int n, m, mat[103][103];
int  main() {
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            in >> mat[i][j];
    int p = mat[1][1] ;
    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if (mat[i][j] > p)
                p = mat[i][j];
    p++;
    for (int i = 0; i <= n + 1; i++) {
        mat[i][0] = p++;
        mat[i][m + 1] = p++;
    } for (int j = 1; j <= m; ++j) {
        mat[0][j] = p++;
        mat[n + 1][j] = p++;
    } long long int contor = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            bool adv = true;
            for (int s = 0; s < 3; s++)
                for (int t = s + 1; t < 4; t++)
                    if (mat[i + dlin[s]][j + dcol[s]] == mat[i + dlin[t]][j + dcol[t]])
                        adv = false;
            if (adv) 
                contor++;
        }
    cout << contor;
    return 0;
}