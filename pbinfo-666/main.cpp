#include <iostream>
using namespace std;
int main(){
    int mat[101][101], n, m, nr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 2; i <= n; i = i + 2)
        for (int j = 1; j <= m; j++) {
            bool prim = true;
            int x = mat[i][j];
            if (x < 2) prim = false;
            if (x > 2 && x % 2 == 0) prim = false;
            for (int d = 3; prim && d * d <= x; d = d + 2)
                if (x % d == 0) prim = false;
            if (prim == true) nr++;
        } cout << nr;
    return 0;
}