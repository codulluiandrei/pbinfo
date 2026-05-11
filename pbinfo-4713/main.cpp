#include <fstream>
#include <algorithm>
#define Nmax 100005
#define inFile "sir2dif.in"
#define outFile "sir2dif.out"
using namespace std;
int a[Nmax], n;
int st[Nmax], dr[Nmax];
int main()
{
    int i, minim, maxim, dif2max;
    // citire
    ifstream fin(inFile);
    fin >> n;
    for (i = 1; i <= n; ++i)
        fin >> a[i];
    fin.close();
    // calcul st
    dr[n] = -10000000;
    minim = a[n];
    for (i = n - 1; i >= 1; --i)
    {
        dr[i] = max(a[i]-minim, dr[i+1]);
        minim = min(minim, a[i]);
    }
    // calcul dr
    st[1] = -10000000;
    maxim = a[1];
    for (i = 2; i <= n; ++i)
    {
        st[i] = max(maxim - a[i], st[i - 1]);
        maxim = max(maxim, a[i]);
    }
    // calcul dif2max
    dif2max = (a[1] - a[2]) + (a[3] - a[4]);
    for (i = 2; i <= n - 2; ++i)
        dif2max = max(dif2max, st[i] + dr[i+1]);
    //afisare
    ofstream fout(outFile);
    fout << dif2max << "\n";
    fout.close();
    return 0;
}