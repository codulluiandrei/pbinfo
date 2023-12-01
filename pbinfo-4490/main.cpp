#include <bits/stdc++.h>
using namespace std;

int b[505], g[505], sol[505], n;

void BinaryToGray(int b[], int g[], int n)
{
    g[1] = b[1];
    for (int i = 2; i <= n; i++)
        g[i] = (b[i] + b[i - 1]) % 2;
}

void GrayToBinary(int g[], int b[], int n)
{
    b[1] = g[1];
    for (int i = 2; i <= n; i++)
        b[i] = (g[i] + b[i - 1]) % 2;
}

void Afis(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << "\n";
}

int main()
{
    char s[505];
    cin >> n;
    cin >> (s + 1);
    for (int i = 1; i <= n; i++)
        b[i] = s[i] - '0';
    cin >> (s + 1);
    for (int i = 1; i <= n; i++)
        g[i] = s[i] - '0';
    BinaryToGray(b, sol, n);
    Afis(sol, n);
    GrayToBinary(g, sol, n);
    Afis(sol, n);
    return 0;
}
