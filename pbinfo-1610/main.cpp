//100
#include <fstream>
using namespace std;
int n, i, x, c, maxim, minim, nr, pmaxim, pminim, tip, tipa, sol1, sol2, first, t;
int main () {
    ifstream fin ("colier.in");
    ofstream fout("colier.out");
    fin>>t>>n;
    sol2 = 1;
    for (i=1;i<=n;i++) {
        fin>>x;
        maxim = 0;
        minim = 9;
        nr = 0;
        while (x != 0) {
            c = x % 10;
            nr++;
            if (c > maxim) {
                maxim = c;
                pmaxim = nr;
            }
            if (c < minim) {
                minim = c;
                pminim = nr;
            }
            x /= 10;
        }
        if (pmaxim < pminim) {
            tip = 1;
            sol1++;
        } else {
            tip = 2;
        }
        if (i == 1)
            first = tip;
        else {
            if (tip != tipa) {
                sol2++;
            }
        }
        tipa = tip;
    }
    if (tip == first)
        sol2--;
    if (t == 1)
        fout<<sol1<<"\n";
    else {
        if (sol1 == n || sol1 == 0)
            fout<<"1\n";
        else
            fout<<sol2<<"\n";
    }
    return 0;
}