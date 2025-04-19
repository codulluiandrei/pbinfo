#include <fstream>
using namespace std;
int NR[11], M[11], a[1025], n;
int PrimaCifra(int n)
{
    while (n > 9)
        n /= 10;
    return n;
}
int main()
{
    int i, c, x, optiune;
    ifstream fin("grup.in");
    ofstream fout("grup.out");
    fin >> n >> optiune;
    if (optiune == 1)
    {
        for (i = 0; i <= 9; i++)
            M[i] = 1000000000;
        for (i = 1; i <= n; i++)
        {
            fin >> x;
            c = PrimaCifra(x);
            NR[c]++;
            M[c] = min(M[c], x);
        }
        x = NR[0];
        c = M[0];
        for (i = 1; i <= 9; i++)
            if (NR[i] > x)
            {
                x = NR[i];
                c = M[i];
            }
            else if (x == NR[i]) c = min(c, M[i]);
        fout << c << "\n";
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            fin >> x;
            c = 0;
            if (x == 0) c = 1;
            else while (x > 0)
            {
                c = c | (1 << (x % 10));
                x /= 10;
            }
            a[c]++;
        }
        x = a[0];
        for (i = 1; i <= 1024; i++)
            x = max(x, a[i]);
        fout << x << "\n";
    }
    fout.close();
    return 0;
}