#include <fstream>
using namespace std;
ifstream fin ("bile2.in");
ofstream fout ("bile2.out");
const int N = 1e5 + 5;
long long h[N], k[N], n, m, x, t;
#define max(x,y) ((x)<(y)?(y):(x))
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> h[i] >> k[i];
    for (int i = 0; i < m; ++i) {
        fin >> x >> t;
        int crt = h[x], height = h[x];
        if (t <= h[x]) {
            fout << h[x] - t << "\n";
            continue;
        }
        t -= h[x];
        height = 0;
        crt -= k[x];
        while (t && crt) {
            if (t <= crt) {
                height += t;
                t = 0;
            }
            else {
                t -= crt;
                height = crt;
            }
            if (!t)
                break;
            if (t <= crt) {
                height -= t;
                t = 0;
            }
            else {
                t -= crt;
                height = 0;
            }
            crt = max(0, crt - k[x]);
        }
        fout << height << "\n";
    }
}