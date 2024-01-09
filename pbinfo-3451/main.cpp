#include <iostream>
using namespace std;

int A[21][21],n,m,k,gasit,X[21],P[21];

void afis()
{
    for(int i=1;i<=k+1;i++)
        cout<<X[i]<<" ";
    cout<<"\n";
    gasit=1;
}

void back(int p)
{
    for(int i=1;i<=n;i++)
        if(p==1 || A[X[p-1]][i])
        {
            X[p]=i;
            A[X[p-1]][X[p]]=0;
            if(p==k+1) afis();
            else back(p+1);
            A[X[p-1]][X[p]]=1;
        }
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
    back(1);
    if(!gasit) cout<<"Nu exista";
    return 0;
}
