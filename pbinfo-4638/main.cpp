#include <iostream>
#include <queue>
using namespace std;
int n,m,A[101][101],k,D[101],P[101],dmax;
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
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    BF(k);
    for(int i=1;i<=n;i++)
        if(D[i]>dmax)
            dmax=D[i];
    //cout<<dmax;
    for(int i=1;i<=n;i++)
        if(D[i]==dmax)
                cout<<i<<" ";
    return 0;
}