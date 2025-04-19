#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("bunicul.in");
ofstream g("bunicul.out");
int n, v[20001],i,m,r,j,s,u[20001];
int main()
{
    f>>m>>n>>r;
    s=0;
    for(i=0;i<n;i++)
    {
        f>>v[2*i]>>v[2*i+1];
        s+=v[2*i+1]-v[2*i]+1;
    }
    s=m-s+1;
    g<<s<<'\n';
    sort(v,v+2*n);
    int p=-1;
    i=0;
    while(p+1-v[i]==0)
    {
        i+=2;
        p=v[i-1];
    }
    int x;
    j=0; f>>x;
    while(p<=m&&i<2*n&&j<r)
    {
        if(x<v[i]-p)
        {
            u[2*j]=p+1;
            u[2*j+1]=p+x;
            p+=x;
            f>>x;j++;
        }
        else
        {
            i+=2;
            p=v[i-1];
        }
    }
    int ok=1;
    while(p<=m&&j<r&&ok)
    {
        if(x<=m-p)
        {
            u[2*j]=p+1;
            u[2*j+1]=p+x;
            p+=x;
            f>>x;j++;
        }
        else ok=0;
    }
    if(j<r)
    {
        g<<j<<" "<<u[(j-1)*2+1];
    }
    else
        for(i=0;i<r;i++)
        {
            g<<u[2*i]<<" "<<u[2*i+1]<<" ";
        }
    return 0;
}