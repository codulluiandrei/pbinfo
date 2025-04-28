#include <bits/stdc++.h>
using namespace std;
int n, m, b[50003];
priority_queue<int> Q;
int Aleator(int L)
{
    int i, x = rand();
    for (i = 1; i <= 20; i++)
        x = 1LL * x * rand() % L + 1;
    return x;
}
int main()
{
    int i, x;
    long long smax;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        Q.push(-x);
    }
    for (i = 1; i <= m; i++)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    for (i = 1; i <= m; i++)
        if (b[i] > -Q.top())
        {
            Q.pop();
            Q.push(-b[i]);
        }
    smax = 0;
    while (!Q.empty())
    {
        smax -= Q.top();
        Q.pop();
    }
    cout << smax;
    return 0;
}