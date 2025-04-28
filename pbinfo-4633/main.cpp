#include <iostream>
#include <queue>
using namespace std;
int n,m,g,A[101][101],k,D[101],P[101],B[101][101],c;
queue<int> Q;
void BF(int i)
{
    P[i]=1;
    D[i]=0;
    Q.push(i);
    while(!Q.empty())
    {
        i=Q.front();
        Q.pop();
        for(int j=1;j<=n;j++)
        if(!P[j] && A[i][j]==1)
        {
            P[j]=1;
            D[j]=D[i]+1;
            Q.push(j);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            P[j]=D[j]=0;
        BF(i);
        for(int j=1;j<=n;j++)
            B[i][j]=D[j];
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            fout<<B[i][j]<<" ";
        fout<<endl;
    }*/
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(B[i][j]==B[j][i] && B[i][j]>0)
            {
                cout<<i<<" "<<j<<endl;
                c++;
            }
    if(c==0) cout<<"Nu exista";
    return 0;
}