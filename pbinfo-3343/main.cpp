#include <iostream>
using namespace std;
int n;
int a[101][101];
void gen_impar(int n, int a[][101]){
    int c;
    c = (n*n*n + n)/2;
    int nr = 1;
    /// general
    for(int x = 0, y = n-1;x<n;++x, --y)
        for(int i=x, j=y;i<x+n;++i, ++j)
            a[i][j] = nr++;
    /// N
    for(int x=0, y=n-1;x<n/2;++x, --y)
        for(int j=y, cnt=0;cnt<=x;j+=2, ++cnt)
            a[x+n][j] = a[x][j], a[x][j]=0; /// sau swap
    /// S
    for(int x=2*(n-1), y=n-1, ln = 0;x>=n+n/2;--x, --y, ++ln)
        for(int j=y, cnt=0;cnt<=ln;j+=2, ++cnt)
            a[x-n][j] = a[x][j], a[x][j]=0;
    /// V
    for(int x = n-1, y = 0;y<n/2;--x, ++y)
        for(int i=x, cnt=0; cnt<=y; i+=2, ++cnt)
            a[i][y+n] = a[i][y], a[i][y] = 0;
    /// E
    for(int x = n-1, y = 2*(n-1), ln = 0;y>=n+n/2;--x, --y, ++ln)
        for(int i=x, cnt=0; cnt<=ln; i+=2, ++cnt)
            a[i][y-n] = a[i][y], a[i][y] = 0;
    /// transpunere din (n/2, n/2) in (0, 0)
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            a[i][j] = a[i+n/2][j+n/2];
}
int main()
{
    int b[101][101]; /// indici
    cin>>n;
    gen_impar(n/2, b);
    /// generam matricea tip
    char tip[51][51];
    int k = n/4+1;
    for(int i=0;i<k;++i)
        for(int j=0;j<n/2;++j)
            tip[i][j] = 'L';
    for(int j=0;j<n/2;++j)
        tip[k][j] = 'U';
    for(int i=k+1;i<n/2;++i)
        for(int j=0;j<n/2;++j)
            tip[i][j] = 'X';
    swap(tip[n/4][n/4], tip[n/4+1][n/4]);
    /// generam matricea rezultat
    for(int i=0, x=0;i<n;i+=2, ++x)
        for(int j=0, y=0;j<n;j+=2, ++y)
    {
        if(tip[x][y] == 'L')
        {
            a[i][j] = 4*b[x][y];
            a[i+1][j+1] = 4*b[x][y]-1;
            a[i+1][j] = 4*b[x][y]-2;
            a[i][j+1] = 4*b[x][y]-3;
        }
        else if(tip[x][y] == 'U')
        {
            a[i][j] = 4*b[x][y]-3;
            a[i+1][j+1] = 4*b[x][y]-1;
            a[i+1][j] = 4*b[x][y]-2;
            a[i][j+1] = 4*b[x][y];
        }
        else if(tip[x][y] == 'X')
        {
            a[i][j] = 4*b[x][y]-3;
            a[i+1][j+1] = 4*b[x][y]-2;
            a[i+1][j] = 4*b[x][y]-1;
            a[i][j+1] = 4*b[x][y];
        }
    }
    for(int i=0;i<n;++i, cout<<'\n')
        for(int j=0;j<n;++j)
            cout<<a[i][j]<<' ';
    return 0;
}