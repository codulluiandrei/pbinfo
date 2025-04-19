#include <bits/stdc++.h>
using namespace std;
priority_queue<int> Q;
int main()
{
    int i, x, y, n, s;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        Q.push(-x);
    }
    s = 0;
    for (i = 1; i < n; i++)
    {
        x = -Q.top();
        Q.pop();
        y = -Q.top();
        Q.pop();
        x += y;
        s += x;
        Q.push(-x);
    }
    cout << s;
    return 0;
}