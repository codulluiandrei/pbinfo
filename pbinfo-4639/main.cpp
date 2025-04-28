#include <iostream>
using namespace std;
int A[101][101],n,m,S[101],c,k,C[101],nc;
void DF(int v, int c)
{
    S[v]=c;
    for(int i=1;i<=n;i++)
        if(!S[i] && A[v][i])
            DF(i,c);
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
    for(int i=1;i<=n;i++)
        if(!S[i])
        {
            nc++;
            DF(i,nc);
        }
    //for(int i=1;i<=n;i++)
        //cout<<S[i]<<" ";
    for(int i=1;i<=n;i++)
        C[S[i]]++;
    for(int i=1;i<=nc;i++)
        if(C[i]==k)
            c++;
    cout<<c;
    return 0;
}