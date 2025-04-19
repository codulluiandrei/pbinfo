#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> M;
string a[100001];
int n;
int main()
{
    int nrMax = 0;
    string s;
    while (cin >> s)
    {
        sort(s.begin(), s.end());
        M[s]++;
        if (nrMax < M[s]) nrMax = M[s];
    }
    cout << nrMax << "\n";
    return 0;
}