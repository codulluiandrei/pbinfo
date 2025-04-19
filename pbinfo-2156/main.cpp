// Autor: Mihai Enache
#include <fstream>
using namespace std;
const int MAX_N = 1000002;
int N, cerinta;
int punctaje[MAX_N], ultim[MAX_N];
int main() {
    ifstream f("adlic.in");
    ofstream g("adlic.out");
    f >> cerinta >> N;
    for(int i = 1; i <= N; ++i) {
        f >> punctaje[i];
    }
    if(cerinta == 1) {
        int maxP = 0;
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            if(punctaje[i] < punctaje[i - 1]) {
                ans = punctaje[i];
                break;
            }
        }
        g << ans << "\n";
    }
    else {
        int nrClase = 0;
        for(int i = 1; i <= N; ++i) {
            int l = 1;
            int r = nrClase;
            int clasa = 0;
            while(l <= r) {
                int m = (l + r) / 2;
                if(ultim[m] <= punctaje[i]) {
                    clasa = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            if(clasa) {
               ultim[clasa] = punctaje[i];
            }
            else {
                ++nrClase;
                ultim[nrClase] = punctaje[i];
            }
        }
        g << nrClase << "\n";
    }
    f.close();
    g.close();
    return 0;
}