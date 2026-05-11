#include <iostream>
using namespace std;
int A[101][101],n,m,S[101],P[101],c,k,C[101],nc;
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
    for(int i=1;i<=n;i++)
        if(!S[i])
        {
            nc++;
            DF_succ(i,nc);
            DF_pred(i,nc);
            for(int j=1;j<=n;j++)
                if(S[j]!=P[j])
                    S[j]=P[j]=0;
        }
    for(int i=1;i<=n;i++)
        C[S[i]]++;
    for(int i=1;i<=nc;i++)
        if(C[i]==k)
            c++;
    cout<<c;
    return 0;
}