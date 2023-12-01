///100p
#include <fstream>
#include <iostream>
using namespace std;
int n, c, sum, L, sol1, sol2, x, k, sc, nr, i;
int main () {
    ifstream fin ("sss.in");
    ofstream fout("sss.out");
    fin>>c;
    fin>>n;

    L = 0;
    sum = 0;
    while (sum < n) {
        L++;
        sum += L;
    }

    for (i=1;i<=n;i++) {
        fin>>x;

        if (i == 1) {
            k = x;
            while (k%10 == 0)
                k /= 10;
            k = k%10;
        }

        if (i+k-1 >= n)
            sol1 += x;

        sc += x;
        nr++;
        if (nr == L) {
            if (sc > sol2) {
                sol2 = sc;
            }
            L--;
            nr = 0;
            sc = 0;
        }
    }
    if (c == 1)
        fout<<sol1<<"\n";
    else
        fout<<sol2<<"\n";
    return 0;
}

