#include <bits/stdc++.h>
#define nmax 100003
using namespace std;
int a[nmax], st[nmax], dr[nmax], n;
void Citire()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[n + 1] = n + 1;
}
void StangaDreapta()
{
    int i, x;
    stack<int> q;
    q.push(0);
    for (i = 1; i <= n; i++)
    {
        x = a[i];
        while (x > a[q.top()])
            q.pop();
        st[i] = i - q.top();
        q.push(i);
    }
    /// golire stiva
    while (!q.empty()) q.pop();
    q.push(n + 1);
    for (i = n; i >= 1; i--)
    {
        x = a[i];
        while (x > a[q.top()])
            q.pop();
        dr[i] = q.top() - i;
        q.push(i);
    }
}
void CostTotal()
{
    long long cost = 0;
    for (int i = 1; i <= n; i++)
        cost += 1LL * st[i] * dr[i] * a[i];
    cout << cost << "\n";
}
int main()
{
    Citire();
    StangaDreapta();
    CostTotal();
	return 0;
}