#include <iostream>
#include <fstream>
using namespace std;
ifstream in("gradina.in");
ofstream out("gradina.out");
#define cin in
#define cout out
int n, p, k, mat[1001][1001];
long long int S[1005][1005];
long long int maxim = -1, contor = 0;
int main() {
    cin >> n >> p >> k;
    for (int i = 0; i <= n; i++)
        S[i][0] = 0;
    for (int j = 0; j <= n; j++)
        S[0][j] = 0;
    for (int i = 1; i <= p; i++) {
        int lin, col;
        cin >> lin >> col;
        mat[lin][col] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + mat[i][j];

    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++) {
                long long int suma = S[i][j] - S[i - k][j] - S[i][j - k] + S[i - k][j - k];
                if (suma > maxim)
                    maxim = suma, contor = 1;
                else if (suma == maxim)
                    contor++;
        }

    cout << maxim << "\n";
    cout << contor;  
    
    return 0;
}