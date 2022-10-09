#include <iostream>
using namespace std;
int mat[33][33], v[100], n, var = 0, S = 0;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            S = S + mat[i][j];
            v[var] = S;
        } while (S > 0) {
        S = v[var];
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (mat[i][j] == 1) {
                    int contor = 0;
                    if (mat[i - 1][j] == 0) contor++;
                    if (mat[i + 1][j] == 0) contor++;
                    if (mat[i][j - 1] == 0) contor++;
                    if (mat[i][j + 1] == 0) contor++;
                    if (contor >= 2) {
                        S--;
                        mat[i][j] = 2;
                    }
                }
        var++;
        v[var] = S;
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (mat[i][j] == 2)
                    mat[i][j] = 0;
    } cout << var << "\n";
    for (int i = 0; i < var; i++) 
        cout << v[i] << "\n";
    return 0;
}