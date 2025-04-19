#include <fstream>
#include <queue>
#define nmax 1005
#define pmax 256
using namespace std;
ifstream f("lumini.in");
ofstream g("lumini.out");
int n, m, h[pmax * pmax *pmax + 5];
class color {
public:
    int r, g, b;
    int get_hash() const {
        return r * 256 * 256 + g * 256 + b;
    }
    int get_opposite_hash() const {
        color p;
        p.r = 256 - r;
        p.g = 256 - g;
        p.b = 256 - b;
        p.r %= 256; p.g %= 256; p.b %= 256;
        return p.get_hash();
    }
    int get_intensity() const {
        int x = 0, y = 0, z = 0;
        if (r)
            x = g / r;
        if (g)
            y = b / g;
        if (b)
            z = r / b;
        return (x * x + y * y + z * z) * 1000;
    };
} v[nmax][nmax];
#include <set>
set <int> my_set[nmax * nmax];
const int dl[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
int zone[nmax][nmax], nr_zone;
void clear() {
    for (int i = 1; i <= nr_zone; i++)
        my_set[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            zone[i][j] = 0;
    nr_zone = 0;
}
int verify(int sol)
{
    int i, j;
    queue <pair<int, int > > q;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            if (zone[i][j] == 0) {
                zone[i][j] = ++nr_zone;
                q.push(make_pair(i,j));
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int i1 = x+ dl[k];
                        int j1 = y + dc[k];
                        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m)
                            if (zone[i1][j1] == 0)
                               if (abs(v[x][y].get_intensity() - v[i1][j1].get_intensity()) <= sol) {
                                  zone[i1][j1] = zone[x][y];
                                  set <int> :: iterator it = my_set[zone[i1][j1]].find(v[i1][j1].get_opposite_hash());
                                  if (it != my_set[zone[i1][j1]].end()) {
                                      clear(); return false;
                                  }
                                  my_set[zone[i1][j1]].insert(v[i1][j1].get_hash());
                                  q.push(make_pair(i1, j1));
                        }
                    }
                }
            }
        }
    clear();
    return true;
}
int main()
{
    int i, j, cer;
    f >> n >> m >> cer;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            f >> v[i][j].r >> v[i][j].g >> v[i][j].b;
            h[v[i][j].get_hash()] ++;
            //g << v[i][j].get_hash() << '\n';
        }
    if (cer == 1) {
        color mid;
        mid.r = 128;
        mid.g = 128;
        mid.b = 128;
        long long cnt = 1LL * h[0] * (h[0] - 1) +  1LL * h[mid.get_hash()] * (h[mid.get_hash()] - 1);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if ((v[i][j].r == 0 && v[i][j].g == 0 && v[i][j].b == 0) ||
                    (v[i][j].r == 128 && v[i][j].g == 128 && v[i][j].b == 128)) {
                } else {
                    cnt += h[v[i][j].get_opposite_hash()];
                }
        g << cnt / 2 << '\n';
        return 0;
    }
    int sol = 0;
    for (i = 1 << 26; i; i >>= 1) {
        if (verify(sol + i))
            sol += i;
    }
    g << sol << '\n';
    return 0;
}