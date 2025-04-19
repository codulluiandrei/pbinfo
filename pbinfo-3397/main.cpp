// Sursa: Dragan Andrei-Gabriel
#include <bits/stdc++.h>
using namespace std;
int t, n, k, ans, frecv[10005], a, b, nrA, nrB, v[100005];
int main()
{
    freopen("gard.in", "r", stdin);
    freopen("gard.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        a = b = -1;
        nrA = nrB = 0;
        ans = 1;
        scanf("%d", &n);
        if (n <= 100000)
        {
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &v[i]);
            }
            sort(v + 1, v + n + 1);
            int temp = 1;
            int index = 1;
            while (index <= n)
            {
                while (v[index] == v[index + 1] && index <= n)
                    temp++, index++;
                if (temp > 0)
                {
                    if (a == -1)
                        a = temp; else
                        if (a == temp)
                            nrA++; else
                        if (a != -1 && a != temp && b == -1)
                            b = temp; else
                                if (b == temp)
                                    nrB++; else
                            if (a != -1 && b != -1 && a != temp && b != temp)
                                {
                                    ans = -1;
                                    break;
                                }
                }
                index++;
                temp = 1;
            }
            if (b != -1 && ans != -1)
            {
                if (abs(a - b) > 1)
                    ans = 0;
                if (a < b && (nrA - nrB != 1) && (nrA - nrB != 0))
                    ans = 0;
                if (b < a && (nrB - nrA != 1) && (nrB - nrA != 0))
                    ans = 0;
            }
            if (b != -1 && ans != -1 && ((nrA == 0 && a == 1) || (b == 1 && nrB == 0)))
                ans = 1;
            if (b != -1 && ans != -1 && (nrB == 0 && ((b - a == 1) || (b - a == 0))))
                ans = 1;
            if (b != -1 && ans != -1 && (nrA == 0 && ((a - b == 1) || (a - b == 0))))
                ans = 1;
        } else
        {
            memset(frecv, 0, sizeof(frecv));
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &k);
                frecv[k]++;
            }
            for (int i = 1; i <= 10000; i++)
            if (frecv[i] > 0)
            {
                if (a == -1)
                    a = frecv[i]; else
                    if (a == frecv[i])
                        nrA++; else
                    if (a != -1 && a != frecv[i] && b == -1)
                        b = frecv[i]; else
                            if (b == frecv[i])
                                nrB++; else
                        if (a != -1 && b != -1 && a != frecv[i] && b != frecv[i])
                            {
                                ans = -1;
                                break;
                            }
            }
            if (b != -1 && ans != -1)
            {
                if (abs(a - b) > 1)
                    ans = 0;
                if (a < b && (nrA - nrB != 1) && (nrA - nrB != 0))
                    ans = 0;
                if (b < a && (nrB - nrA != 1) && (nrB - nrA != 0))
                    ans = 0;
            }
            if (b != -1 && ans != -1 && ((nrA == 0 && a == 1) || (b == 1 && nrB == 0)))
                ans = 1;
            if (b != -1 && ans != -1 && (nrB == 0 && ((b - a == 1) || (b - a == 0))))
                ans = 1;
            if (b != -1 && ans != -1 && (nrA == 0 && ((a - b == 1) || (a - b == 0))))
                ans = 1;
        }
        printf("%d\n", ans >= 1);
    }
    return 0;
}