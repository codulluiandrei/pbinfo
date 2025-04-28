// prof. Chesca Ciprian
// sursa cu recurenta pe matrice ~ 100 p
// O(N^2)
#include <fstream>
#define nmax 5001
#define M 3000017
using namespace std;
int m[nmax][nmax],a[nmax][nmax];
int x[nmax],y[nmax];
ifstream fin("npath.in");
ofstream fout("npath.out");
int main()
{
    int i,j,n,k,d,x0,y0;
    fin >> n >> k;
    // 1  = lipsa unei linii orizontale si 2 = lipsa unei linii verticale din pozitia (x0,y0)
    for(i=1;i<=k;i++)
        {
        fin >> x0 >> y0 >> d;
        if (d == 1) a[x0][y0]+=d;
        if (d == 2) a[x0][y0]+=d;
        }
    // adaug restrictiile
    // calculez vectorii x si y ce reprezinta valorile lui m de pe prima linie respectiv prima coloana
    if (a[0][0]==1 || a[0][0]==3) x[0] = 0;
                                 else x[0] = 1;
    for(i=1;i<=n;i++)
        if (a[0][i] == 1 || a[0][i] == 3) x[i] = 0;
            else  x[i] = x[i-1] && 1;
    if (a[0][0] == 2 || a[0][0] == 3) y[0] = 0;
        else y[0] = 1;
    for(j=1;j<=n;j++)
        if (a[j][0] == 2 || a[j][0] == 3 ) y[j] = 0;
          else y[j] = y[j-1] && 1;
    // calculez elementul din coltul (0,0) al matricei m
    if (a[0][0]==3) m[0][0]=0;
              else
                {
                if (a[0][0]==2 && (a[0][1]==1 || a[0][1] == 0)) m[0][0]=1;
                if (a[0][0]==1 && (a[1][0]==2 || a[1][0] == 0)) m[0][0]=1;
                if (a[0][0]==0 && (a[1][0])==0 || a[1][0] == 2) m[0][0]++;
                if (a[0][0]==0 && (a[0][1])==0 || a[0][1] == 1) m[0][0]++;
                }
    // calculez recurent prima linie din matricea m
    for(i=1;i<=n;i++)
        {
        if (a[0][i+1] == 0 || a[0][i+1] == 1) m[0][i]=(m[0][i]+x[i])%M;
        if (a[1][i] == 0 || a[1][i] == 2) m[0][i]=(m[0][i]+m[0][i-1])%M;
        }
    // calculez recurent prima coloana din matricea m
    for(i=1;i<=n;i++)
        {
        if (a[i+1][0] == 0 || a[i+1][0] == 2) m[i][0]=(m[i][0]+y[i])%M;
        if (a[i][1] == 0 || a[i][1] == 1) m[i][0]=(m[i][0]+m[i-1][0])%M;
        }
    // calculez recurent restul elementelor din matrice
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
              {
               if (a[i][j+1] == 0 || a[i][j+1] == 1) m[i][j]=(m[i][j]+m[i-1][j])%M;
               if (a[i+1][j] == 0 || a[i+1][j] == 2) m[i][j]=(m[i][j]+m[i][j-1])%M;
              }
    fout << m[n-1][n-1]<<"\n";
	fout.close();
    return 0;
}