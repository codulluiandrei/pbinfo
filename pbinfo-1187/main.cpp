/*
    prof Constantin Galatan
    Complexitate: O(Q * T * log(n)^3)
*/
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
struct Cell {
    int i, j;
    bool operator < (const Cell& c) const {
        if (i != c.i )
            return i < c.i;
        return j > c.j;
    }
};
int n, m;
vector<Cell> cl;
int mx[1002][1002];
int Query(int i, int j);
void Update(int i, int j, int val);
void Reset(int i, int j);
int CountRobots(int L); // O(T * log(n)^2)
int main()
{
    ifstream fin("roboti1.in");
    ofstream fout("roboti1.out");
    int x, y, p, T, L;
	fin >> p >> n >> m >> T;
    for (int i = 0; i < T; ++i)
    {
        fin >> x >> y;
   //   assert(x <= n && y <= m);
        cl.push_back({x, y});
    }
    sort(cl.begin(), cl.end());
    if (p == 1) // O(T * log(n)^2)
    {
        fin >> L;
        fout << CountRobots(L) << '\n';
    }
    else // O(Q * T * log(n)^3)
    {
       int Q, k, lo, hi, Lmin;
        for (fin >> Q; Q--; fout << Lmin << '\n')
        {
            fin >> k;
            lo = 1, hi = n / k + 1;
            while (lo <= hi)
            {
                L = (lo + hi) / 2;
                if (CountRobots(L) <= k)
                {
                    Lmin = L;
                    hi = L - 1;
                }
                else
                    lo = L + 1;
            }
        }
    }
    fin.close();
    fout.close();
}
int CountRobots(int L) // O(T * log(n)^2)
{
    int cnt(0), cntUp(0);
    for (const auto& c : cl)
    {
        cntUp = 1;
        if (c.i > L && c.j <= m - L)
            cntUp += Query(c.i - L, m - c.j - L + 1);
        Update(c.i, m - c.j + 1, cntUp);
        cnt = max(cnt, cntUp);
    }
    for (const auto& c : cl)
        Reset(c.i, m - c.j + 1);
    return cnt;
}
void Reset(int ic, int jc)
{
    for (int i = ic; i <= n; i += i & -i)
        for (int j = jc; j <= m; j += j & -j)
            mx[i][j] = 0;
}
void Update(int ic, int jc, int val)
{
    for (int i = ic; i <= n; i += i & -i)
        for (int j = jc; j <= m; j += j & -j)
            mx[i][j] = max(mx[i][j], val);
}
int Query(int ic, int jc)
{
    int cnt(0);
    for (int i = ic; i >= 1; i -= i & -i)
        for (int j = jc; j >= 1; j -= j & -j)
            cnt = max(cnt, mx[i][j]);
    return cnt;
}