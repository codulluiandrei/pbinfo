#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
long long prim[1000010];
int expp[1000010], p = 0;
int main ()
{
    ifstream cin ("copii.in");
    ofstream cout ("copii.out");
    int c, k;
    long long x;
    cin >> c >> x;
    assert (c == 1 || c == 2);
    if (c == 1)
    {
        cin >> k;
        assert (1LL <= x && x <= 1000000LL);
        assert (1 <= k && k <= 9);
        int m = 1;
        for (int i = 1; i <= k; ++i)
            m *= 10;
        assert (m > 0);
        int nr2 = 0, nr5 = 0;
        for (int i = 1; i <= x; ++i)
        {
            int ci = i;
            while (ci % 5 == 0)
            {
                ++nr5;
                ci /= 5;
            }
        }
        nr2 = nr5;
        long long prod = 1LL;
        for (int i = 1; i <= x; ++i)
        {
            int ci = i;
            while (ci % 2 == 0 && nr2 > 0)
            {
                --nr2;
                ci /= 2;
            }
            while (ci % 5 == 0 && nr5 > 0)
            {
                --nr5;
                ci /= 5;
            }
            prod *= 1LL * ci;
            prod %= 1LL * m;
        }
        int aux = prod, p = 0;
        while (aux > 0)
        {
            ++p;
            aux /= 10;
        }
        for (int i = p + 1; i <= k; ++i)
            cout << 0;
        cout << prod << '\n';
    }
    else
    {
        assert (1LL <= x && x <= 1000000000000LL);
        long long i = 2LL;
        while (i * i <= x)
        {
            if (x % i == 0LL)
            {
                prim[++p] = i;
                while (x % i == 0)
                {
                    x /= i;
                    ++expp[p];
                }
            }
            i += 1LL;
        }
        if (x > 1LL)
        {
            prim[++p] = x;
            expp[p] = 1;
        }
        long long divizor = 1LL, numar = 1LL;
        for (int i = 1; i <= p; ++i)
        {
            if (expp[i] % 2 == 1) --expp[i];
            for (int j = 1; j <= expp[i]; ++j)
                divizor *= prim[i];
            numar *= 1LL * (1 + expp[i]);
        }
        cout << divizor << " " << numar << '\n';
    }
    return 0;
}