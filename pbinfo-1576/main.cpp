#include <fstream>
using namespace std;
ifstream f("zona3.in");
ofstream g("zona3.out");
int n,m,i,j,h,v[101][101],k[50000];
void bk(int i, int j) {
    k[h]++;
    v[i][j]=h;
    if (v[i-1][j]==1 && i-1>0) bk(i-1,j);
    if (v[i+1][j]==1 && i+1<=n) bk(i+1,j);
    if (v[i][j-1]==1 && j-1>0) bk(i,j-1);
    if (v[i][j+1]==1 && j+1<=m) bk(i,j+1);
}
int main()
{
    h=1;
    f>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            f>>v[i][j];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (v[i][j]==1) {h++; bk(i,j);}
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++)
            g<<k[v[i][j]]<<' ';
            g<<'\n';
    }
    return 0;
}