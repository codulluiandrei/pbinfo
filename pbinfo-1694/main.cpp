#include <fstream>
#include <cmath>

using namespace std;

int t, n, k, a, sol, d, e, nr, i, x, ok, r, amax = 0, amin = 2000000000;

int main () {
    ifstream fin ("norocos.in");
    ofstream fout("norocos.out");

    fin>>t>>n>>k;
    for (i=1;i<=n;i++) {
        fin>>x;
        if (t == 1 && x%2 == 1) {
            a++;
            if (x < amin) {
                amin = x;
            }
            if (x > amax) {
                amax = x;
            }
        }
        if (x == 1)
            continue;
        if (t == 2) {
            ok = 1;
            r = (int)sqrt(x);
            d = 2;
            nr = 0;
            while (x != 1 && d <= r) {
                if (x%d == 0) {
                    e = 0;
                    while (x%d == 0) {
                        x /= d;
                        e++;
                    }
                    if (e != 1) {
                        ok = 0;
                        break;
                    }
                    nr++;
                    if (nr > k) {
                        ok = 0;
                        break;
                    }
                }
                d++;
            }
            if (x!=1)
                nr++;
            if (nr != k)
                ok = 0;
            if (ok) {
                sol++;
            }
        }
    }

    if (t == 1) {
        if (a == 0) {
            fout<<a<<"
";
        } else {
            fout<<amin<<" "<<amax<<"
";
        }

    } else
        fout<<sol<<"
";

    return 0;
}
