#include <iostream>
using namespace std;

int A[101][101],n,m,k,gasit;

int GE(int v)
{
    int c=0;
    for(int i=1;i<=n;i++)
        if(A[v][i]==1) c++;
    return c;
}

int GI(int v)
{
    int c=0;
    for(int i=1;i<=n;i++)
        if(A[i][v]==1) c++;
    return c;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
    }
    for(int i=1;i<=n;i++)
        if(GE(i)+GI(i)==k)
        {
            cout<<i<<" ";
            gasit=1;
        }
    if(!gasit) cout<<"Nu exista";
    return 0;
}
