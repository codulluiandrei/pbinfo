#include <fstream>
using namespace std;
ifstream fin("lac_x.in");
ofstream fout("lac_x.out");
int A[1001][1001],n,m,maxi,maxp;
void fill(int i, int j, int &aria)
{
    A[i][j]=2;
    aria++;
    if(A[i-1][j]==1) fill(i-1,j,aria);
    if(A[i][j+1]==1) fill(i,j+1,aria);
    if(A[i+1][j]==1) fill(i+1,j,aria);
    if(A[i][j-1]==1) fill(i,j-1,aria);
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fin>>A[i][j];
    for(int i=1;i<=n;i++)
    {
        if(A[i][1]==1) { int a=0; fill(i,1,a); if(a>maxp) maxp=a; }
        if(A[i][m]==1) { int a=0; fill(i,m,a); if(a>maxp) maxp=a; }
    }
    for(int i=1;i<=m;i++)
    {
        if(A[1][i]==1) { int a=0; fill(1,i,a); if(a>maxp) maxp=a; }
        if(A[n][i]==1) { int a=0; fill(n,i,a); if(a>maxp) maxp=a; }
    }
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
            if(A[i][j]==1) { int a=0; fill(i,j,a); if(a>maxi) maxi=a; }
    fout<<maxi<<" "<<maxp;
    return 0;
}