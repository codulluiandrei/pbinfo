#include <bits/stdc++.h>
#define nmax 1001
using namespace std;

int a[nmax], b[nmax]; /// relatiile initiale
int viz[nmax]; /// viz[i] = 1 daca i a fost deja pus in clasament
bitset<nmax> f;
int n, m;

void Citire()
{
    int i;
    ifstream fin("competitie.in");
    fin >> n >> m;
    for (i = 1; i <= m; i++)
        fin >> a[i] >> b[i];
    fin.close();
}

void Clasament()
{
    int i, pas, k;
    ofstream fout("competitie.out");
    for (pas = 1; pas <= n; pas++)
    {
        /// cauta cel mai mic i care nu apare in b[]
        /// adica cel mai mic i cu f[i]=0
        f.reset();
        for (i = 1; i <= m; i++)
            f[b[i]] = 1;
        for (i = 1; f[i] == 1 || viz[i] == 1; i++)
            ;
        fout << i << " ";
        viz[i] = 1;
        /// elimin din a[] relatiile care-l contin pe i
        for (k = 1; k <= m; k++)
            if (a[k] == i) a[k] = b[k] = 0;
    }
    fout.close();
}

int main()
{
    Citire();
    Clasament();
    return 0;
}
