#include <bits/stdc++.h>

using namespace std;
ifstream fin("div11.in");
ofstream fout("div11.out");
typedef long long ll;
ll f[2][12];// 0 -> restul 1 la inmultire, 1 -> restul 10 la inmultire
ll v[100005],n;
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>v[i];
        ll aux=v[i];
        ll nrcif=0;
        while(aux)
        {
            nrcif++;
            aux/=10;
        }
        f[nrcif%2][v[i]%11]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll aux=v[i];
        ll nrcif=0;
        while(aux)
        {
            nrcif++;
            aux/=10;
        }
        f[nrcif%2][v[i]%11]--;
        ll rest=v[i]%11;
        ll need=(11-rest)%11;
        ans+=f[0][need];
        rest=((v[i]%11)*10LL)%11;
        need=(11-rest)%11;
        ans+=f[1][need];
        f[nrcif%2][v[i]%11]++;
    }
    fout<<ans;
    return 0;
}
