#include <bits/stdc++.h>
using namespace std;
ifstream  fin("sumesubsecv.in");
ofstream fout("sumesubsecv.out");
int a[100000], n;
int main()
{
    int i, n, answer, s, len;
    fin >> n;
    for (i = 0; i < n; i++)
        fin >> a[i];
    s = answer = a[0];
    len = 1;
    for (i = 1; i < n; i++)
    {
        if (abs(a[i] - a[i - 1]) == 1)
        {
            len++;
            s = (s + 1LL * a[i] * len) % 1000000007;
        }
        else
        {
            s = a[i];
            len = 1;
        }
        answer = (answer + s) % 1000000007;
    }
    fout << answer << "\n";
    fin.close();
    fout.close();
    return 0;
}