#include <fstream>
using namespace std;
ifstream fin("moscraciun_6.in");
ofstream fout("moscraciun_6.out");
int A[102][102],n,m,ck,k;
void fill(int i, int j, int &c)
{
    if(A[i][j]==2) c++;
    A[i][j]=0;
    if(A[i-1][j]>0 && i>=1) fill(i-1,j,c);
    if(A[i+1][j]>0 && i<=n) fill(i+1,j,c);
    if(A[i][j+1]>0 && j<=m) fill(i,j+1,c);
    if(A[i][j-1]>0 && j>=1) fill(i,j-1,c);
}
int main()
{
    fin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fin>>A[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]!=0)
            {
                int c=0;
                fill(i,j,c);
                if(c>=k) ck++;
            }
    fout<<ck;
    return 0;
}