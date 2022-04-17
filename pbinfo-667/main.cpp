#include <bits/stdc++.h>
using namespace std;
bool prim(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d = d + 2) {
        if (n % d == 0)
        	return false;
    } return true;
}
int main() {
    int mat[601][601], n, m, nr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1 ; j <= m ; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; j = j + 2)
    		if (prim(mat[i][j]) == true)
    			nr++;
    cout << nr;
    return 0;
}
