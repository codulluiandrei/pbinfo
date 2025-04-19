#include <fstream>
using namespace std;
int a[20005], n, k;
int main()
{
    int i, j, x, y, cnt, nrDeputati, s;
    ifstream fin("politic.in");
    fin >> k;
    n = 0;
    fin >> x;
    cnt = 1;
    for (i = 2; i <= k; ++i)
    {
        fin >> y;
        if (x + 1 == y) cnt++;
        else {a[++n] = cnt; cnt = 1;}
        x = y;
    }
    a[++n] = cnt;
    nrDeputati = 0;
    for (i = 1; i <= n; ++i)
        nrDeputati += a[i];
    nrDeputati /= 2;
    i = 1;
    s = 0;
    cnt = 0;
    for (j = 0; j<= n; )
    {
        if (s > nrDeputati)
        {
            cnt += (n - j + 1);
            s -= a[i];
            i++;
        }
        else
        {
            j++;
            s += a[j];
        }
    }
    ofstream fout("politic.out");
    fout << n << "\n" << cnt << "\n";
    fout.close();
    return 0;
}