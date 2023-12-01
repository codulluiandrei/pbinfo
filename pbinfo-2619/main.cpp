// Complexitate O(n)
#include <iostream>
using namespace std;

long long a[5];

int main()
{
    int i, j, k, n;
    long long cnt, x1, x2, A, B, C;
    cin >> n >> x1 >> A >> B >> C;
    a[x1 % 5]++;
    for (i = 2; i <= n; i++)
    {
        x2 = (x1 * A + B) % C;
        a[x2 % 5]++;
        x1 = x2;
    }
    cnt = 0;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
            for (k = j; k < 5; k++)
                if ((i + j + k) % 5 == 0)
                {
                    if (i == j && j == k)
                        cnt += (a[i] * (a[i] - 1) * (a[i] - 2) / 6);
                    else if (i == j)
                        cnt += (a[i] * (a[i] - 1) / 2 * a[k]);
                    else if (j == k)
                        cnt += (a[j] * (a[j] - 1) / 2 * a[i]);
                    else
                        cnt += (a[i] * a[j] * a[k]);
                }
    cout << cnt << "\n";
    return 0;
}
