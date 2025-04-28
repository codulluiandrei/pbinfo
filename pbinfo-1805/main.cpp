#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include <limits>
#define pb push_back
#define mp make_pair
#define NMAX 100
#define KMAX 1000
using namespace std;
ifstream fin("expeditie.in");
ofstream fout("expeditie.out");
int dp[NMAX][NMAX][KMAX];
bool inQueue[NMAX][NMAX][KMAX];
int n, m, k;
int a[NMAX][NMAX];
int T[NMAX][NMAX];
queue<pair<pair<int, int>, int> > q;
pair<pair<int, int>, int> curr;
int INF = numeric_limits<int>::max();
int x[] = {-1, -1, 0, 1, 1, 1, 0, -1}, y[] = {0, 1, 1, 1, 0, -1, -1, -1};
void Read ()
{
    fin >> n >> m >> k;
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            fin >> a[i][j];
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            fin >> T[i][j];
}
bool Verif (int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m) return true;
    return false;
}
int BF(int cap)
{
    int i, j, s;
    int time, capacity;
    pair<int,int> vt;
    for(i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            for(s = 0; s <= cap; ++s)
            {
                dp[i][j][s] = INF;
                inQueue[i][j][s] = false;
            }
        q.push({{1,1},cap});
        inQueue[1][1][cap] = true;
        dp[1][1][cap] = 0;
        while(!q.empty())
        {
            curr = q.front();
            if (a[curr.first.first][curr.first.second] < 0)
            {
                dp[curr.first.first][curr.first.second][cap] = dp[curr.first.first][curr.first.second][curr.second];
                curr.second = cap;
            }
            for (i = 0; i < 8; ++i)
            {
                if (Verif(curr.first.first + x[i], curr.first.second + y[i]))
                {
                    vt.first = curr.first.first + x[i];
                    vt.second = curr.first.second + y[i];
                    time = T[vt.first][vt.second];
                    capacity = abs(a[vt.first][vt.second]);
                    if (capacity <= curr.second && dp[curr.first.first][curr.first.second][curr.second] + time < dp[vt.first][vt.second][curr.second - capacity])
                    {
                        dp[vt.first][vt.second][curr.second - capacity] = dp[curr.first.first][curr.first.second][curr.second] + time;
                        if (inQueue[vt.first][vt.second][curr.second - capacity] == false)
                        {
                            inQueue[vt.first][vt.second][curr.second - capacity] = true;
                            q.push({{vt.first, vt.second}, curr.second - capacity});
                        }
                    }
                }
            }
            q.pop();
            inQueue[curr.first.first][curr.first.second][curr.second] = false;
        }
    int minim = INF;
    for(i = 0; i <= cap; ++i)
      if(dp[n][m][i] < minim) minim = dp[n][m][i];
    return minim;
}
void Solve ()
{
    int left, right, mid;
    int distMin = BF(k);
    if (distMin == INF) fout << "Nu exista drum\n";
    else
    {
        left = 1;
        right = k;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            if (BF(mid) == distMin) right = mid - 1;
            else left = mid + 1;
        }
        fout << distMin << "\n" << left;
    }
}
int main ()
{
    Read();
    Solve();
    return 0;
}