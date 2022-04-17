#include <fstream>
using namespace std;
ifstream in("sumainsecv.in");
ofstream out("sumainsecv.out");
int main() {
    int n, K, v[105];
    in >> n >> K;
    int st = 0, dr = 0;
    for (int i = 1; i <= n; ++i)
        in >> v[i];
    for (int i = 1; i <= n && st == 0; ++i)
        for (int j = i; j <= n && st == 0; ++j) {
            int S = 0;
            for (int k = i; k <= j; ++k)
                S = S + v[k];
            if (S == K)
                st = i, dr = j;
        }
    out << st << " " << dr;
    return 0;
}
