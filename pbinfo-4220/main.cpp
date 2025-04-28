#include <fstream>
using namespace std;
ifstream cin("masina.in");
ofstream cout("masina.out");
int g[1001];
int main()
{
    int m,i,n,d,refill=0,j,stop=0;
    cin>>d>>m>>n;
    for(i=1; i<=n; i++)
        {cin>>g[i];}
        n++;
        g[n]=d;
    g[0]=0;
    i=0;
    while(i<=n)
    {
        j=i;
        while(g[j]-g[i]<=m && j<=n)j++;
        if(i==j-1){stop=1;
                cout<<-1; i=n+1;}
        else
        if(j<=n)
        {
            refill++;
            i=j-1;
            //cout<<g[i]<<" ";
        }
        else
        i=n+1;
    }
    if(stop==0)
    cout<<refill;
    return 0;
}