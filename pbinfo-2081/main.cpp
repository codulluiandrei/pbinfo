#include <bits/stdc++.h>
using namespace std;
int readInt ()
{
    bool minus = false;
    int raspuns = 0;
    char c;
    while (true)
    {
        c = getchar();
        if (c == EOF) return 100001;
        if (c == '-')
        {
            minus = true;
            break;
        }
        if (c>='0' && c<='9')
        {
            raspuns = c-'0';
            break;
        }
    }
    while (true)
    {
        c = getchar();
        if (c<'0' || c>'9') break;
        raspuns = 10*raspuns + c-'0';
    }
    if (minus == true) return -raspuns;
    return raspuns;
}
int main()
{
    freopen ("parsare.in", "r", stdin);
    freopen ("parsare.out", "w", stdout);
    int x, maxim = -100001;
    while (true)
    {
        x = readInt();
        if (x == 100001)
        {
            cout << maxim;
            return 0;
        }
        maxim = max(maxim, x);
    }
    return 0;
}