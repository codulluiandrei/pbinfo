#include <fstream>

using namespace std;
ifstream fin("spirala2.in");
ofstream fout("spirala2.out");
int n,k,i,j,p,nr,v[501][501],s,w[501][501],a,b,x,y;
int main()
{
    fin>>p>>n>>k;
    for (a=1; a<=n; a++) {
        x=a; y=n-a+1;
        for (int i=x; i<=y; i++) {nr++;v[x][i]=nr;}
        for (int i=x+1; i<=y; i++) {nr++;v[i][y]=nr;}
        for (int i=y-1; i>x-1; i--) {nr++;v[y][i]=nr;}
        for (int i=y-1; i>x; i--){nr++;v[i][x]=nr;}
    }
    if (p==1) {
        for (i=1; i<=n; i++) {
            if (i!=k) s+=v[i][k]%100003+v[k][i]%100003;
        }
        fout<<s;
    }
    else {
        for (i=1; i<=n; i++)
        {
            w[i][k]=v[k][i];
            w[k][i]=v[i][k];
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++)
                if (!w[i][j]) fout<<v[i][j]<<' ';
                else fout<<w[i][j]<<' ';
            fout<<'\n';
        }
    }
    return 0;
}
