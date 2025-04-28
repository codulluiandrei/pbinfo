#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#define DN 1005
using namespace std;
int n,q,rez,cnt[2],x;
string m[DN];
bitset<DN> viz[DN],l,c;
void dfs(int a,int b) {
  ++cnt[m[a][b]-'0'];
  viz[a][b]=1;
  if(c[b] && !viz[n-a-1][b]) dfs(n-a-1,b);
  if(l[a] && !viz[a][n-b-1]) dfs(a,n-b-1);
}
int main() {
  ifstream f("mapal.in");
  ofstream g("mapal.out");
  f>>n;
  for(int i=0; i<n; ++i) f>>m[i];
  for(f>>q;q--;) {f>>x; --x; l[x]=1;}
  for(f>>q;q--;) {f>>x; --x; c[x]=1;}
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(!viz[i][j] && (l[i] || c[j])) {
    cnt[0]=cnt[1]=0;
    dfs(i,j);
    rez+=min(cnt[0],cnt[1]);
  }
  g<<rez;
}