#include <bits/stdc++.h>
using namespace std;
char s[35];
map<int, int> M;
int main()
{
    int i, j, x, m, n, C;
    long long answer;
    ifstream fin("complementar.in");
    ofstream fout("complementar.out");
    fin >> n >> m;
    C = (1 << m) - 1;
    answer = 0;
    for (i = 1; i <= n; i++)
    {
        fin >> s;
        x = 0;
        for (j = 0; s[j]; j++)
            x = x * 2 + (s[j] - '0');
        answer += M[C ^ x];
        M[x]++;
    }
    fout << answer << "\n";
    fin.close();
    fout.close();
    return 0;
}