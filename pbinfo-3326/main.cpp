#include <iostream>

using namespace std;
int f[101],f1[101];
int main()
{
    int n,m,a;
    char c;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>c>>a;
        f1[a]++;
        if(c=='D')
        {
            f[a]++;
        }
        else
            f[a]--;
    }
    int maxx=0,cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(f1[i]==0)
            cnt1++;
        if(f[i]>0)
            cout<<i<<" ";
        if(f1[i]>maxx)
        {
            maxx=f1[i];
        }
    }
    cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        if(f1[i]==maxx)
            cout<<i<<" ";
    }
    cout<<'\n'<<cnt1;
    return 0;
}