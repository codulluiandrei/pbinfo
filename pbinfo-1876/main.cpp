#include <fstream>
using namespace std;
int sol[100001], k, n, p, put, r[100001];
void adaugare (int x)
{
    if (k == 0)
    {
        sol[k++] = x;
        return ;
    }
    if (x >= sol[k-1])
    {
        sol[k++] = x;
        return ;
    }
    if (x<sol[0])
    {
        sol[0] = x;
        return;
    }
    int p=1, put = 0, i, poz = 0;
    while (p<<1 <= k)
    {
        p = p<<1;
        ++put;
    }
    for (i = put; i>=0; --i)
    {
        if (poz + p < k && x >= sol[poz+p])
            poz+=p;
        p>>=1;
    }
    sol[poz+1] = x;
}
int main()
{
    ifstream fin ("sclm2.in");
    ofstream fout ("sclm2.out");
    int i, j = 0, x, copie;
    fin >> n;
    for (i = 0; i<n; ++i)
    {
        fin >> x;
        adaugare(x);
    }
    fout << k;
    return 0;
}