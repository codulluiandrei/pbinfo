#include <iostream>
#include <cmath>
using namespace std;
int n, k, st[16], v[16];
int G;
void Afis()
{
    if (abs(G - st[n - 1]) > k) return;
    for (int i = 1; i < n; i++)
        cout << st[i] << " ";
    cout << G << "\n";
}
void Back(int top)
{
    if (top == n) Afis();
    else for (int i = max(1, st[top-1] - k); i <= n && i <= st[top-1] + k; i++)
        if (v[i] == 0)
        {
            st[top] = i;
            v[i] = 1;
            G ^= i;
            Back(top + 1);
            v[i] = 0;
            G ^= i;
        }
}
int main()
{
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        G ^= i;
    for (i = 1; i <= n; i++)
    {
        st[1] = i;
        v[i] = 1;
        G ^= i;
        Back(2);
        G ^= i;
        v[i] = 0;
    }
    return 0;
}