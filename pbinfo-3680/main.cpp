#include <fstream>
using namespace std;
ifstream cin ("numere.in");
ofstream cout("numere.out");
int v[100010],s[100010];
int p,n,m,t,kmax,nmax;
int nrDivPrim(int x)
{
    int d,y=0;
    for(d=2;d<=x/2; d++)
        if(x%d==0)
        y++;
    return y ;
}
int main () {
    int x,y;
    cin>>p>>n;
    if(p==2)
    {
        int k,dif;
        cin>>m>>t;
        for (int i=1;i<=n;++i)
        {
            k=nrDivPrim(i);
            if(k==t)v[i]=1;
        }
        k=0;
        for (int i=2;i<=n;++i)v[i]+=v[i-1];
        for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            {
                if((dif=v[j]-v[i-1])==m)k++;
                else if((dif=v[j]-v[i-1])>m) j=n+1;
            }
        cout<<k;
    }
    else
    {for (int i=1;i<=n;++i)
        {
            int y=nrDivPrim(i);
            if(y>kmax){kmax=y;nmax=i;}
        }
        cout<<nmax;
    }
    return 0;
}