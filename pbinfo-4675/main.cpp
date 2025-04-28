// Mircea Măierean - 100p
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("livada.in");
ofstream fout("livada.out");
vector<int> v;
int n, l;
int main()
{
    fin >> n >> l;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        fin >> x >> y;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int left = 0, right = 0, maxLen = 0;
    while (left < n && right < n)
    {
        while (right + 1 < n && v[right + 1] - v[left] <= l)
            ++right;
        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
        ++left;
    }
    fout << maxLen << '\n';
    return 0;
}