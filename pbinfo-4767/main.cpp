#include <fstream>
#include<algorithm>
using namespace std;
ifstream cin("poza.in");
ofstream cout("poza.out");
long long n, c, i, j, maxim, minim, m, cnt;
int a[300006];
int main()
{
    cin>> c>> n;
    m = n * 3;
    for (int i = 0; i < m; ++i)
    {
        cin>> a[i];
    }
    maxim = minim = a[0];
    if (c == 1)
    {
        for (int i = 0; i < m; ++i)
        {
            if (minim > a[i])
                minim = a[i];
            if (maxim < a[i])
                maxim = a[i];
        }
        cout<< maxim<< ' '<< minim;
    }
    else
    {
        sort(a, a + m);
        j = a[0];
        for (int i = 0; i < 3*n; ++i)
        {
            cnt = 0;
            while (j == a[i])
            {
                cnt++;
                i++;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            cout<< a[i] << ' ';
        }
        cout << '\n';
        for (int i = 2*n - 1; i >= n; i--)
        {
            cout<< a[i] << ' ';
        }
        cout << '\n';
        for (int i = m - 1; i >= 2 * n; i--)
        {
            cout<< a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}