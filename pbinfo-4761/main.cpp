#include <bits/stdc++.h>
using namespace std;
ifstream  fin("bambusi.in");
ofstream fout("bambusi.out");
int h[100002], n, M;
/// returneaza 1 daca taind la inaltimea H se obtin cel putin M metri
/// sau 0 in caz contrar
int MinimumM(int H)
{
    long long suma = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] > H) suma += (h[i] - H);
        if (suma >= M) return 1;
    }
    return 0;
}
int main()
{
    int i, st, dr, mij, H;
    fin >> n >> M;
    for (i = 1; i <= n; i++)
        fin >> h[i];
    st = 0; dr = 1000000000; H = 0;
    while (st <= dr)
    {
        mij = st + (dr - st) / 2;
        if (MinimumM(mij) == 1)
        {
            H = mij;
            st = mij + 1;
        }
        else dr = mij - 1;
    }
    fout << H << "\n";
    return 0;
}