#include <iostream>
using namespace std;
int mat[255][255] = {0}, n, m;
int main() {
    cin  >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    int contor = 0, maxim = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j)
            if (mat[i][j] == 1)
                if (mat[i - 1][j] == 0 && mat[i][j - 1] == 0) {
                    contor++;
                    int itemp = i, jtemp = j;
                    while (mat[i][jtemp] == 1) jtemp++;
                    while (mat[itemp][j] == 1) itemp++;
                    if (maxim < (itemp - i) * (jtemp - j))
                        maxim = (itemp - i) * (jtemp - j);
                }
    cout << contor << " " << maxim << endl;
    return 0;
}