/// Mircea Măierean - 100p
#include <fstream>
#include <queue>
#include <string.h>
using namespace std;
ifstream fin("elicopter.in");
ofstream fout("elicopter.out");
const int NMAX = 1000;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int a[NMAX][NMAX], n, m, maxVal;
char viz[NMAX][NMAX];
inline bool ok(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && !viz[x][y];
}
bool check(int val)
{
    queue<pair<int, int>> q;
    memset(viz, 0, sizeof(viz));
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][1] <= val)
        {
            q.push({i, 1});
            viz[i][1] = 1;
        }
    }
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        if (node.second == m)
            return true;
        for (int k = 0; k < 4; ++k)
        {
            int x = node.first + dx[k];
            int y = node.second + dy[k];
            if (ok(x, y) && a[x][y] <= val)
            {
                q.push({x, y});
                viz[x][y] = 1;
            }
        }
    }
    return false;
}
int binarySearch()
{
    int l = 1, r = maxVal, mid = 0, ans = maxVal;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            if (mid > ans)
                break;
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int main(int argc, char *argv[])
{
    // fin = ifstream(argv[1]);
    // fout = ofstream(argv[2]);
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];
            maxVal = max(maxVal, a[i][j]);
        }
    fout << binarySearch() << '\n';
    return 0;
}