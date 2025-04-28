#include <bits/stdc++.h>
#define NMAX 200005
#define cin fin
#define cout fout
using namespace std;
ifstream fin("magazin.in");
ofstream fout("magazin.out");
int n, m;
char s[NMAX], t[NMAX];
int v[NMAX][30], aux[30];
bool ver(int x)
{
    for(int i=0; i<26; ++i)
        if(aux[i]>v[x][i])
            return 0;
    return 1;
}
int main()
{
    cin>>n;
    cin>>(s+1);
    for(int i=1; i<=n; ++i)
        v[i][s[i]-'a']++;
    for(int i=2; i<=n; ++i)
        for(int j=0; j<26; ++j)
            v[i][j]+=v[i-1][j];
    cin>>m;
    for(int i=1; i<=m; ++i)
    {
        for(int j=0; j<26; ++j) aux[j]=0;
        cin>>t;
        for(int j=0; t[j]; ++j)
            aux[t[j]-'a']++;
        for(int i=1; i<=n; ++i)
            if(ver(i))
            {
                cout<<i<<'\n';
                break;
            }
    }
    return 0;
}