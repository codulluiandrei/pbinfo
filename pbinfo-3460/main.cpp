/// Solutie - Moca Andrei - 100p
#include <bits/stdc++.h>
namespace FastRead {
    const int Dim(5000);
    char ibuf[Dim];
    int ipos, ilen;
    char nc()
    {
        if (ipos == ilen)
        {
            ipos = 0;
            ilen = fread(ibuf, 1, Dim, stdin);
            if (!ilen) return EOF;
        }
        return ibuf[ipos++];
    }
    template<class T> void read(T& x)
    {
        char ch;
        int sgn = 1;
        while (!isdigit(ch = nc()))
            if (ch == '-')
                sgn = -1;
        x = ch - '0';
        while (isdigit(ch = nc()))
            x = x * 10 + (ch - '0');
        x *= sgn;
    }
}
using namespace FastRead;
using namespace std;
const int N(1e8);
int lp[N + 1];
vector<int> pr;
int n, x, to;
int64_t res;
int main()
{
    for (int i = 3; i <= N; i += 2) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.emplace_back(i);
        }
        to = min(N / i, lp[i]);
        for (int j = 0; j < static_cast<int>(pr.size()) && pr[j] <= to; ++j)
            lp[i * pr[j]] = pr[j];
    }
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(x);
        if (x % 2 == 0 && x > 1)
            res += 2;
        else res += lp[x];
    }
    cout << res;
    return 0;
}