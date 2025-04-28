#include <fstream>
#define nmax 105
#define mmax 105
using namespace std;
ifstream f("zana.in");
ofstream g("zana.out");
int a[nmax][mmax], b[nmax][mmax];
int n, m, k, n1=0, n2=0;
void citire()
{
    f >> n >> m >> k;
    int i, j, p;
    for(p = 1; p <=k; p++)
    {
        f >> i >> j;
        a[i][j] ++;
    }
    f.close();
}
void fill(int i, int j, int v)
{
    if(b[i][j]==0)
    {
        b[i][j]=v;
        if(a[i][j]>n1)
        {
            n1=a[i][j];
            n2=1;
        }
        else
        {
            if(a[i][j]==n1)
                n2++;
        }
        if(a[i][j]==0)
        {
            if(a[i][j+1]>=0)
                fill(i,j+1,v+1);
            if(a[i][j-1]>=0)
                fill(i,j-1,v+1);
            if(a[i-1][j]>=0)
                fill(i-1,j,v+1);
            if(a[i+1][j]>=0)
                fill(i+1,j,v+1);
        }
    }
}
int main()
{
    citire();
    int i;
    for(i=0;i<=n+1;i++)
        a[i][0]=a[i][m+1]=-1;
    for(i=0;i<=m+1;i++)
        a[0][i]=a[n+1][i]=-1;
    for(i=0;i<=n+1;i++)
        b[i][0]=b[i][m+1]=-1;
    for(i=0;i<=m+1;i++)
        b[0][i]=b[n+1][i]=-1;
    fill(1,1,1);
    g << n1 << endl << n2 << endl;
    g.close();
    return 0;
}