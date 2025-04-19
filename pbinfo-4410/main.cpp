#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<61)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa (void)system("pause");
#define dbg(x) std::cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) std::cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)std::cerr<<x[_]<<' ';std::cerr<<'\n',aaa
#define dbgs(x) std::cerr<<(#x)<<"[stl]: ";for(auto _:x)std::cerr<<_<<' ';std::cerr<<'\n',aaa
#define dbgp(x) std::cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define dbgsp(x) std::cerr<<(#x)<<"[stl pair]:\n";for(auto _:x)std::cerr<<_.fi<<' '<<_.se<<'\n';aaa
#define maxn 1000
using namespace std;
int spl[maxn+5][maxn+5], spc[maxn+5][maxn+5], spd[maxn+5][maxn+5];
int d[maxn+5][maxn+5];
const int mod = 1000000007;
void madd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void msub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//  ifstream cin("input.txt");
  ifstream cin("turcane.in");
  ofstream cout("turcane.out");
  int tip; cin >> tip;
  int n, m; cin >> n >> m;
  int p; cin >> p; ///max dreapta.
  int q; cin >> q; ///max jos.
  int r; cin >> r; ///max diag.
  int i, j, z;
  if (tip == 1) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        d[i][j] = inf;
      }
    }
    ///greedy: urm mutare e intotdeauna max intr-o directie. (sau max pana ajung intr-un perete)
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (i == 1 && j == 1) d[1][1] = 0;
        ///dreapta.
        z = min(p, m-j);
        d[i][j+z] = min(d[i][j+z], 1 + d[i][j]);
        ///jos.
        z = min(q, n-i);
        d[i+z][j] = min(d[i+z][j], 1 + d[i][j]);
        ///diagonala.
        z = min({r, n-i, m-j});
        d[i+z][j+z] = min(d[i+z][j+z], 1 + d[i][j]);
        ///cai.
        if (i+2 <= n && j+1 <= m) d[i+2][j+1] = min(d[i+2][j+1], 1 + d[i][j]);
        if (i+1 <= n && j+2 <= m) d[i+1][j+2] = min(d[i+1][j+2], 1 + d[i][j]);
      }
    }
    cout << d[n][m];
  } else {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (i == 1 && j == 1) {
          d[1][1] = 1;
          spl[1][1] = 1; ///suma pe prefixul liniei lui i.
          spc[1][1] = 1;
          spd[1][1] = 1;
        } else {
          if (i-2 >= 1 && j-1 >= 1) madd(d[i][j], d[i-2][j-1]);
          if (i-1 >= 1 && j-2 >= 1) madd(d[i][j], d[i-1][j-2]);
          z = max(1, j-p);
          madd(d[i][j], spl[i][j-1]);
          msub(d[i][j], spl[i][z-1]);
          z = max(1, i-q);
          madd(d[i][j], spc[i-1][j]);
          msub(d[i][j], spc[z-1][j]);
          z = min({i-1, j-1, r});
          madd(d[i][j], spd[i-1][j-1]);
          msub(d[i][j], spd[i-z-1][j-z-1]);
          ///dupa ce calculez d[i][j].
          spl[i][j] = spl[i][j-1];
          madd(spl[i][j], d[i][j]);
          spc[i][j] = spc[i-1][j];
          madd(spc[i][j], d[i][j]);
          spd[i][j] = spd[i-1][j-1];
          madd(spd[i][j], d[i][j]);
        }
      }
    }
    cout << d[n][m];
  }
  return 0;
}