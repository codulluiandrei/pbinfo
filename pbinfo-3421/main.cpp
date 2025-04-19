#include <iostream>
using namespace std;
int A[101][101],n,m,S[101],P[101],c,k;
void DF_succ(int v, int c)
{
    S[v]=c;
    for(int i=1;i<=n;i++)
        if(!S[i] && A[v][i])
            DF_succ(i,c);
}
void DF_pred(int v, int c)
{
    P[v]=c;
    for(int i=1;i<=n;i++)
        if(!P[i] && A[i][v])
            DF_pred(i,c);
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
    DF_succ(k,1);
    DF_pred(k,1);
    for(int j=1;j<=n;j++)
        if(S[j]!=P[j])
            S[j]=P[j]=0;
    for(int i=1;i<=n;i++)
        if(S[i]==1)
            c++;
    cout<<c;
    return 0;
}