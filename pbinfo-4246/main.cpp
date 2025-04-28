#include <bits/stdc++.h>
#define modulo 123457
#define  inFile "banana.in"
#define outFile "banana.out"
using namespace std;
vector < pair<int,int> > h[modulo];
int n, k, a[16001], m, cnt;
void Citire()
{
    int i, x, y, rest;
    ifstream fin(inFile);
    fin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        fin >> x >> y;
        rest = (x * 10007 + y) % modulo;
        h[rest].push_back(make_pair(x, y));
    }
    fin.close();
}
void Fill(int x, int y)
{
    int r, gasit;
    unsigned i;
    r = (x * 10007 + y) % modulo;
    gasit = 0;
    for (i = 0; i < h[r].size() && !gasit; ++i)
        if (h[r][i].first == x && h[r][i].second == y)
        {
            gasit = 1;
            cnt++;
            h[r][i] = h[r][h[r].size()-1];
            h[r].pop_back();
            Fill(x - 1, y);
            Fill(x + 1, y);
            Fill(x, y - 1);
            Fill(x, y + 1);
        }
}
void FillPeHash()
{
    int p, i, j;
    m = 0; /// numarul de zone
    for (p = 0; p < modulo; p++)
        while (h[p].size() > 0)
        {
            i = h[p][0].first;
            j = h[p][0].second;
            m++;
            cnt = 0;
            Fill(i, j);
            a[m] = cnt;
        }
    sort(a + 1, a + m + 1,greater<int>());
    p = 0;
    for (i = 1; i <= k; i++)
        p += a[i];
    ofstream fout(outFile);
    fout << p << "\n";
    fout.close();
}
int main()
{
    Citire();
    FillPeHash();
    return 0;
}