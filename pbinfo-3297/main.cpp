#include <bits/stdc++.h>
using namespace std;
#define nmax 105
ifstream f("fmi_orase1.in");
ofstream g("fmi_orase1.out");
int main ()
{
    int i, j, v[nmax], rez=0, n;
    f>>n;
    for (i=1; i<=n; i++)
        f>>v[i];
    ///pentru fiecare pereche de pereti
    ///calculam capacitatea bazinului format de acestia
    for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
            rez=max(rez, min(v[i], v[j])*(j - i));
    g<<rez;
    f.close();
    g.close();
}