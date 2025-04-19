/*
   Complexitate O(n) - 100 puncte
*/
#include <iostream>
#include <fstream>
#include <cstring>
#define Nmax 300005
#define inFile  "dominant.in"
#define outFile "dominant.out"
using namespace std;
char s[Nmax];
int x[2*Nmax], y[2*Nmax], *st, *dr;
int optiune;
int main()
{
    int i, n, suma, vmin, vmax, lgMax;
    /// citire
    ifstream fin(inFile);
    ofstream fout(outFile);
    fin >> optiune;
    fin >> (s + 1);
    s[0] = '*';
    n = strlen(s + 1);
    suma = 0;
    for (i = 1; i <= n; i++)
        if (s[i] == '1') suma++;
        else suma--;
    if (suma > 0) /// intregul sir este dominant
    {
        if (optiune == 1) fout << n << "\n";
        else fout << "1\n";
        fout.close();
        return 0;
    }
    st = x + Nmax;
    dr = y + Nmax;
    /// initializare st si dr
    for (i = -n; i <= n; ++i)
    {
        st[i] = 10000000;
        dr[i] = -10000000;
    }
    /// calcul st si dr
    /// st[i] = cea mai din stanga pozitie unde apare valoarea i
    /// dr[i] = cea mai din dreapta pozitie unde apare valoarea i
    st[0] = dr[0] = 0;
    suma = 0;
    vmin = 10000000;
    vmax = -10000000;
    for (i = 1; s[i]; ++i)
    {
        if (s[i] == '0') suma--;
        else suma++;
        st[suma] = min(st[suma], i);
        dr[suma] = max(dr[suma], i);
        vmin = min(vmin, suma);
        vmax = max(vmax, suma);
    }
    /// lungimea maxima a secventei
    lgMax = 0;
    for (i = vmin; i < vmax; i++)
        lgMax = max(lgMax, dr[i+1] - st[i]);
    /// numarul de aparitii ale secventei maximale
    int s0, s1;
    s0 = s1 = suma = 0;
    for (i = 1; i <= lgMax; ++i)
        if (s[i] == '0') s0++;
        else s1++;
    if (s1 > s0) suma++;
    for (i = lgMax + 1; s[i]; ++i)
    {
        if (s[i-lgMax] == '0') s0--;
        else s1--;
        if (s[i] == '0') s0++;
        else s1++;
        if (s1 > s0) suma++;
    }
    if (optiune == 1)
        fout << lgMax << "\n";
    else fout << suma << "\n";
    fout.close();
    fin.close();
    return 0;
}