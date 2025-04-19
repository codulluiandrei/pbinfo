#include <iostream>
using namespace std;
int GE[101],GI[101],n,m,gasit;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        GE[x]++;
        GI[y]++;
    }
    for(int i=1;i<=n;i++)
    if(GE[i] && GI[i] && (GE[i]%GI[i]==0 || GI[i]%GE[i]==0))
    {
        cout<<i<<" ";
        gasit=1;
    }
    if(!gasit) cout<<"NU EXISTA";
    return 0;
}