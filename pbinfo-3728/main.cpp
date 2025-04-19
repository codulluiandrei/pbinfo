#include <fstream>
#include <iostream>
using namespace std;
ifstream fin ("campionat.in");
ofstream fout("campionat.out");
int v[1001];
int a[1001][1001];
int n, i, j, sol[1001], maxim, ok, p, t, d, nr, campioane;
int main () {
    fin>>t;
    fin>>n;
    for (i=1;i<=n;i++)
        fin>>v[i];
    if (t == 1) {
        fin>>d;
        for (;d--;) {
            fin>>i>>j;
            if (i == j) {
                cout<<"nu e bine";
                return 0;
            }
            if (a[i][j] == 0) {
                v[i]++;
                v[j]++;
            }
            a[i][j] = 1;
            a[j][i] = 1;
        }
        maxim = v[1];
        for (i=1;i<=n;i++)
            if (v[i] > maxim) {
                maxim = v[i];
                nr = 1;
            } else
                if (v[i] == maxim)
                    nr++;
        for (i=1;i<=n;i++)
            if (v[i] == maxim) {
                fout<<i;
                nr--;
                if (nr!=0)
                    fout<<" ";
                else
                    fout<<"\n";
            }
    } else {
        /// t = 2
        fin>>d;
        for (;d--;) {
            fin>>i>>j;
            if (a[i][j] == 0) {
                v[i]+=3;
                v[j]+=3;
            }
            a[i][j] = 1;
            a[j][i] = 1;
        }
        for (i=1;i<=n;i++) {
            ok = 1;
            for (j=1;j<=n;j++)
                if (i!=j) {
                    p = v[j];
                    if (a[i][j])
                        p-=3;
                    if (p >= v[i]) {
                        ok = 0;
                        break;
                    }
                }
            if (ok) {
                sol[++campioane] = i;
            }
        }
        for (i=1;i<=campioane;i++) {
            fout<<sol[i];
            if (i!=campioane)
                fout<<" ";
            else
                fout<<"\n";
        }
        if (campioane == 0)
            fout<<"0\n";
    }
    return 0;
}