#include <fstream>
#define inFile "subsets.in"
#define outFile "subsets.out"
using namespace std;
int t[10005], n, k;
void Citire()
{
    ifstream fin(inFile);
    fin >> k;
    fin.close();
}
void Produs(int x)
{
    int i, carry, cif;
    carry = 0;
    for (i = 1; i <= n; ++i)
    {
        cif = t[i] * x + carry;
        t[i] = cif % 10;
        carry = cif / 10;
    }
    while (carry > 0)
    {
        t[++n] = carry % 10;
        carry /= 10;
    }
}
void Calcul()
{
    int i, q, r;
    n = 0;
    i = k;
    while (i > 0)
    {
        t[++n] = i % 10;
        i /= 10;
    }
    k--;
    q = k / 25;
    r = k % 25;
    for (i = 1; i <= q; ++i)
        Produs(1<<25);
    if (r > 0)
        Produs(1 << r);
}
void Afis()
{
    int i;
    ofstream fout(outFile);
    for (i = n; i >= 1; --i)
        fout << t[i];
    fout << "\n";
    fout.close();
}
int main()
{
    Citire();
    Calcul();
    Afis();
    return 0;
}