#include <fstream>
using namespace std;
ifstream in("memory003.in");
ofstream out("memory003.out");
long long int prod[1001], p, n, m, temp, S = 0;
int main() {
    in >> n >> m >> p;
    for (int i = 1; i <= m; i++)
        prod[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
        in >> temp;
        prod[j] = (prod[j] % p * temp % p) % p;
    } for (int i = 1; i <= m; i++)
        S = S + (prod[i] == 0);
    out << S << "\n";
    return 0;
}