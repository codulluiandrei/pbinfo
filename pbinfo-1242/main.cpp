/*
    ecluze - O(n) 100 p
    prof. Eugen Nodea
*/
# include <fstream>
# include <algorithm>
# define NM 100005
# define inf 999999999
using namespace std;
ifstream f("ecluze.in");
ofstream g("ecluze.out");
int i, j, n, m;
int Min[NM], last[NM], urm[NM], a[NM];
int main ()
{
    f >> n;
    for (i=1; i<=n; ++i)
    {
        f >> a[i];
        Min[i] = inf;
    }
    for (i=n; i>=1; --i)
        if (last[a[i]] == 0) last[a[i]] = i;
                        else urm[i] = last[a[i]], last[a[i]] = i;
    Min[1] = 0;
    for (i=1; i<=n; ++i)
    {
        if (i>1)    Min[i] = min(Min[i], Min[i-1] + 1);
        if (urm[i]) Min[urm[i]] = min(Min[urm[i]], Min[i] + (urm[i] - i - 1));
    }
    g << Min[n] << "\n";
    return 0;
}