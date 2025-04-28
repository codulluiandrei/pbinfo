#include <fstream>
const int NMAX=1005;
const int MOD=1e9+7;
using namespace std;
ifstream fin("enigma.in");
ofstream fout("enigma.out");
int dp[NMAX][NMAX], a[NMAX][NMAX];
int scdp[NMAX][NMAX], sldp[NMAX][NMAX];
int n, m, l, c, k;
int main()
{
  int i, j, q;
  fin>>n>>m>>l>>c;
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      fin>>a[i][j];
    }
  }
  fin>>k;
  dp[1][1]=1;
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      if(a[i][j]==0 && !(i==1 && j==1))
      {
        dp[i][j]=(scdp[i-1][j]+sldp[i][j-1])%MOD;
      }
      scdp[i][j]=(dp[i][j]+scdp[i-1][j])%MOD;
      sldp[i][j]=(dp[i][j]+sldp[i][j-1])%MOD;
      if(i>k) scdp[i][j]=(scdp[i][j]-dp[i-k][j]+MOD)%MOD;
      if(j>k) sldp[i][j]=(sldp[i][j]-dp[i][j-k]+MOD)%MOD;
    }
  }
  fout<<dp[l][c]<<'\n';
}