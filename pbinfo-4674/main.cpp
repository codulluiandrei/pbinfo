#include <fstream>
#include <limits.h>
using namespace std;
const int NMAX = 1000005;
int a[NMAX], k, n;
bool check(int s)
{
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (sum >= s)
        {
            ++cnt;
            if (cnt == k)
                return true;
            sum = 0;
        }
    }
    return false;
}
long long binary_search()
{
    long long l = 0, r = INT_MAX, m = 0, ans = 0;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (check(m))
        {
            if (m < ans)
                break;
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}
int main(int argc, char *argv[])
{
    // ifstream fin(argv[1]);
    // ofstream fout(argv[2]);
    ifstream fin("betisoare.in");
    ofstream fout("betisoare.out");
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    fout << binary_search() << '\n';
    return 0;
}