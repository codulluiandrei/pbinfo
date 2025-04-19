#include <fstream>
using namespace std;
int c, n, minim, i, s, d, sol;
int v[100010], ms[100010], md[100010];
int main () {
    ifstream fin ("cadouri.in");
    ofstream fout("cadouri.out");
    fin>>c>>n;
    minim = 2000000000;
    for (i=1;i<=n;i++) {
        fin>>v[i];
        if (v[i] < minim)
            minim = v[i];
    }
    for (i=2;i<=n;i+=2) {
        s = v[i] + v[i-1];
        ms[i] = max(ms[i-2], s);
    }
    for (i=n-1;i>=1;i-=2) {
        d = v[i] + v[i+1];
        md[i] = max(md[i+2], d);
    }
    if (c == 1) {
        fout<<n/2<<" ";
    } else {
        if (n%2 == 0) {
            fout<<ms[n]<<" ";
        } else { /// n impar
            for (i=1;i<=n;i++) {
                if (v[i] == minim) {
                    if (i%2 == 1) {
                        /// minim pe pozitie impara
                        sol = max(sol, ms[i-1]);
                        sol = max(sol, md[i+1]);
                    } else {
                        sol = max(sol, v[i-1]+v[i+1]);
                        sol = max(sol, ms[i-2]);
                        sol = max(sol, md[i+2]);
                    }
                }
            }
            fout<<sol<<" ";
        }
    }
    if (n%2 == 1) {
        fout<<minim<<"\n";
    } else {
        fout<<"0\n";
    }
    return 0;
}