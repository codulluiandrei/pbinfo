#include <iostream>
using namespace std;
int n, mat[101][101], slin[101], scol[101];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
        	slin[i] = slin[i] + mat[i][j];
        	scol[j] = scol[j] + mat[i][j];
    	} int contor = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (slin[i] == scol[j])
                contor++;
    cout << contor << " ";
    return 0;
}