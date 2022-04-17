#include <iostream>
using namespace std;
int main() {
	int mat[205][205], f[1000], n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i > j && i + j < n + 1)
                f[mat[i][j]] = 1;
    for (int i = 1; i < 1000; ++i)
        if (f[i] == 1)
            cout << i << " ";
    return 0;
}
