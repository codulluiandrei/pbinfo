#include <bits/stdc++.h>
#define RECURSIV 0
using namespace std;
ifstream f("galeti.in");
ofstream g("galeti.out");
void solve_recursiv(int,int,long long);
void solve_iterativ();
int N,From[1000010],To[1000010];
long long E;
int main()
{
    f>>N>>E;
    if(RECURSIV){solve_recursiv(1,N,E);return 0;}
    solve_iterativ();
    return 0;
}
void solve_recursiv(int ST,int DR,long long E)
{
    int n=DR-ST+1;
    if(n==1)return;
    if(E>=2LL*n-3LL)
    {
        solve_recursiv(ST+1,DR,E-1LL*n+1LL);
        g<<ST+1<<' '<<ST<<'\n';
        return;
    }
    solve_recursiv(ST,DR-1,E-1LL);
    g<<DR<<' '<<ST<<'\n';
}
void solve_iterativ()
{
    int ST=1,DR=N,k=0;
    while(ST<DR)
    {
        int n=DR-ST+1;
        if(E>=2LL*n-3LL)
        {
            From[++k]=ST+1;
            To[k]=ST;
            ST++;E-=1LL*n-1LL;
        }
        else
        {
            From[++k]=DR;
            To[k]=ST;
            DR--,E-=1LL;
        }
    }
    for(;k;k--)
        g<<From[k]<<' '<<To[k]<<'\n';
}