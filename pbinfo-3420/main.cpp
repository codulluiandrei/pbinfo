#include <iostream>
using namespace std;

int A[101][101],n,m,S[101],P[101],c;

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
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
    }
    for(int i=1;i<=n;i++)
        if(!S[i])
        {
            c++;
            DF_succ(i,c);
            DF_pred(i,c);
            for(int j=1;j<=n;j++)
                if(S[j]!=P[j])
                    S[j]=P[j]=0;
        }
    c=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(A[i][j]==1 && S[i]!=S[j])
                c++;
    cout<<c<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(A[i][j]==1 && S[i]!=S[j])
                cout<<i<<" "<<j<<endl;
    return 0;
}
