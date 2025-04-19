// solutie 100 pct Mihai Georgescu
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int MAX = 30000;
bool prime[MAX + 1];
void numereprime() {
    double rad = sqrt(MAX);
    for (int i = 1; i <= MAX; ++i)
        prime[i] = true;
    for (int i = 2; i <= rad; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = false;
        }
    }
}
bool pprim(int x, int p) {
    if (x == 1)
        return false;
    while (x % p == 0)
        x /= p;
    return prime[x];
}
int main() {
    ifstream fin("secvente2.in");
    ofstream fout("secvente2.out");
    numereprime();
    int D, n, p, k, m, x;
    fin >> D;
    for (int t = 1; t <= D; ++t) {
        fin >> n >> p >> k;
        m = 0;
        int a[15001];
        for (int i = 1; i <= n; ++i) {
            fin >> x;
            if (pprim(x, p)) {
                ++m;
                a[m] = i;
            }
        }
        if (m - k + 1 <= 0)
            fout << 0 << "\n";
        else
            fout << m - k + 1 << "\n";
        for (int i = 1; i <= m - k + 1; ++i)
            fout << a[i] << " " << a[i + k - 1] << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}