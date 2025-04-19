#include <fstream>
#include <bitset>
using namespace std;
const int NMAX = 1e6 + 1;
long long m[NMAX], aux[NMAX];
int Left[NMAX], Right[NMAX], n, q, k, c, x, y, p;
bitset <NMAX> ok;
ifstream fin("livada2.in");
ofstream fout("livada2.out");
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> m[i];
    int lastIndex = 0;
    for (int i = 1; i <= n; ++i)
    {
        fin >> k;
        ok[i] = k;
         if (ok[i])
            lastIndex = i;
        Left[i] = lastIndex;
    }
    lastIndex = 0;
    for (int i = n; i >= 1; --i)
    {
        if (ok[i])
            lastIndex = i;
        Right[i] = lastIndex;
    }
    fin >> q;
    while (q--)
    {
        fin >> c >> x >> y >> p;
        if (c == 1)
        {
            if (Right[y])
                y = Right[y];
        }
        if (c == 2)
        {
            p = -p;
            if (Left[x])
                x = Left[x];
        }
        aux[x] += p;
        aux[y + 1] -= p;
    }
    for (int i = 1; i <= n; ++i)
    {
        aux[i] += aux[i - 1];
        fout << m[i] + aux[i] << ' ';
    } 
    return 0;
}