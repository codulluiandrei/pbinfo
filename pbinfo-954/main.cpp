#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("joc2.in");
ofstream g ("joc2.out");
int n, m, d[105][105], a[105][105], v[105][105];
void citire ()
{
    f>>n>>m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) f>>v[i][j];
    // for (int i=1; i<=n; i++){ for (int j=1; j<=m; j++) cout<<v[i][j]<<; cout<<endl;}
}
void umplere1 ()
{
    d[1][1]=v[1][1];
    a[1][1]=v[1][m];
    for (int j=2; j<=m; j++)
    {
        d[1][j]=v[1][j]+d[1][j-1];
        a[1][j]=v[1][m-j+1]+a[1][j-1];
    }
    for (int j=2; j<=n; j++)
    {
        d[j][1]=v[j][1]+d[j-1][1];
        a[j][1]=v[j][m]+a[j-1][1];
    }
}
void rezolvare ()
{
    for (int i=2; i<=n; i++)
        for (int j=2; j<=m; j++)
        {
            if (a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j]+v[i][m-j+1];
            else a[i][j]=a[i][j-1]+v[i][m-j+1];
            if (d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j]+v[i][j];
            else d[i][j]=d[i][j-1]+v[i][j];
        }
       // for (int i=1; i<=n; i++){ for (int j=1; j<=m; j++) cout<<a[i][j]<<; cout<<endl;}
    if (d[n][m]>a[n][m]) g<<1<<<<d[n][m];
    else if (d[n][m]<a[n][m]) g<<2<<<<a[n][m];
    else g<<3<<<<d[n][m];
    g<<endl;
}
int main ()
{
    citire ();
    umplere1 ();
    rezolvare ();
}