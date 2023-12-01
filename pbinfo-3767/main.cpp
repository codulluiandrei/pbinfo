#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
int n, c, maxim, sol, k, x, i, j, v[50001], w[50001];
int main () {
    ifstream fin ("ktlon.in");
    ofstream fout("ktlon.out");
    fin>>c;
    fin>>n>>k;

    if (c == 1) {
        sol = 0;
        while (k--) {
            maxim = 0;
            for (i=1;i<=n;i++) {
                fin>>x;
                if (x > maxim)
                    maxim = x;
            }
            int castig = 0;
            for (i=1;i<=n;i++) {
                fin>>x;
                if (x > maxim)
                    castig = 1;
            }
            sol +=  castig;
        }
        fout<<sol<<"\n";
    } else {
        int stele1 = 0;
        int stele2 = 0;
        while (k--) {
            for (i=1;i<=n;i++)
                fin>>v[i];
            for (i=1;i<=n;i++)
                fin>>w[i];
            sort(v+1, v+n+1);
            sort(w+1, w+n+1);
            if (v[n] == w[n])
                continue;
            if (v[n] >= w[n]) {
                i = n;
                while (i > 0 && v[i] > w[n]) {
                    stele1 += v[i];
                    stele1 -= w[i];
                    i--;

                }
                if (n-i > 5) {
                    cout<<"Nu e bine"<<1/0;
                }

            } else {
                i = n;
                while (i > 0 && w[i] > v[n]) {
                    stele2 += w[i];
                    stele2 -= v[i];
                    i--;

                }
                if (n-i > 5) {
                    cout<<"Nu e bine"<<1/0;
                }
            }
        }
        if (stele1 >= stele2)
            fout<<stele1<<"\n";
        else
            fout<<stele2<<"\n";
    }


    return 0;
}
