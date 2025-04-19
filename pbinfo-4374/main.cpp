/*
    Autor: Raileanu Alin-Gabriel
*/
#include <fstream>
const int VALMAX=8005;
const int NMAX=1505;
const int INF=1e9+5;
using namespace std;
ifstream fin("axel.in");
ofstream fout("axel.out");
int cnt[VALMAX], act[VALMAX], fn[VALMAX];
int n, maxim, maxi=-INF, cost;
int a[NMAX][NMAX];
int main()
{
    int i, j;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fin>>a[i][j];
            maxim=max(maxim, a[i][j]);
        }
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=maxim; i++) act[i]=INF;
        for(i=1; i<=n; i++)
        {
            if(i<j) cost=i+(n-j);
            else cost=i-j;
            act[a[i][j]]=min(act[a[i][j]], cost);
        }
        for(i=1; i<=maxim; i++)
        {
            if(act[i]!=INF)
            {
                cnt[i]++;
                fn[i]+=act[i];
            }
        }
    }
    for(i=1; i<=maxim; i++)
    {
        if(cnt[i]==n && i-fn[i]>maxi) maxi=i-fn[i];
    }
    if(maxi!=-INF) fout<<"DA\n"<<maxi<<'\n';
    else fout<<"NU"<<'\n';
    return 0;
}