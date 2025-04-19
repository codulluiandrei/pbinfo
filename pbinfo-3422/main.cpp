#include <iostream>
using namespace std;
const int inf=100;
int A[101][101],n,m,k,gasit;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) A[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(A[i][j]>A[i][k]+A[k][j])
                    A[i][j]=A[i][k]+A[k][j];
    for(int i=1;i<=n;i++)
        if(A[1][i]==k || A[i][1]==k)
        {
            cout<<i<<" ";
            gasit=1;
        }
    if(!gasit) cout<<"Nu exista";
    return 0;
}