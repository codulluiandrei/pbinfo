#include <fstream>
#define int long long
const int NMAX=70005;
const int LGMAX=1e6+5;
const int MMAX=25;
using namespace std;
ifstream fin("sos.in");
ofstream fout("sos.out");
int a[NMAX][MMAX];
int f[LGMAX];
int n, m;
int check(int);
void add(int);
void err(int);
signed main()
{
    int i, j, ans=0;
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i][0];
        for(j=1; j<=a[i][0]; j++)
        {
            fin>>a[i][j];
        }
    }
    for(j=i=1; i<=n; i++)
    {
        while(j<=n && check(j)==(j-i+1))
        {
            add(j);
            j++;
        }
        ans+=(j-i-1);
        err(i);
    }
    fout<<ans<<'\n';
    return 0;
}
int check(int poz)
{
    int maxim=0, i;
    for(i=1; i<=a[poz][0]; i++)
    {
        maxim=max(maxim, f[a[poz][i]]+1);
    }
    return maxim;
}
void add(int poz)
{
    int i;
    for(i=1; i<=a[poz][0]; i++)
    {
        f[a[poz][i]]++;
    }
}
void err(int poz)
{
    int i;
    for(i=1; i<=a[poz][0]; i++)
    {
        f[a[poz][i]]--;
    }
}