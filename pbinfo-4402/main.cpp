/*
Raluca Costineanu, Colegiul National Stefan cel Mare, Suceava
*/
#include <fstream>
#define ll long long
using namespace std;
ifstream f("ciocolata.in");
ofstream g("ciocolata.out");
const int N = 1e5 + 5;
int v[N], n, C, fr[10001];
ll ss, sd;
int main()
{
    f >> C >> n;
    int i, j;
    if (C == 1)
    {
        for (i = 1; i <= n; i++)f >> j, fr[j]++;
        int mx = 0, cioco = 0;
        for (i = 1; i <= 10000; i++)
            if (fr[i] > mx)mx = fr[i], cioco = i;
        g << cioco << '\n';
    }
    else if (C == 2)
    {
        for (i = 1; i <= n; i++)f >> v[i];
        ss = v[1];
        sd = v[n];
        i = 2;
        j = n - 1;
        while (ss < sd && i < j)
            ss += v[i], i++;
        ll smn = ss - sd;
        while (i < j)
        {
            if (ss < sd)
                ss += v[i], i++;
            else
                sd += v[j], j--;
            if (ss >= sd && ss - sd < smn)smn = ss - sd;
            //cout<<ss<<' '<<sd<<'\n';
        }
        g << smn << '\n';
    }
    return 0;
}