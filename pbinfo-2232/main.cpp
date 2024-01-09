#include <bits/stdc++.h>
using namespace std;

ifstream f("retea1.in");
ofstream g("retea1.out");

int A[15001], n;
char c[15001], V[15001];

int main()
{
    int x, i, j;
    f >> n;
    f.get();
    for(i = 1; i <= n; i++)
    {
        V[i] = 0;
        f.get(c, 15001);
        f.get();
        for(j = 0; j < n; j++)
        if(c[2 * j] == '1') A[i] = j + 1;
    }

    for(i = 1; i <= n; i++)
        if(V[i] == 0)
        {
            x = i;
            for(j = 1; j <= n; j++)
                if(V[j] == 1) V[j] = 0;
            while(V[x] != 2)
            {
              V[x]++;
              x = A[x];
            }
        }

    for(i = 1, x = 0; i <= n; i++)
        if(V[i] == 2) x++;
    g << "{";
    for(i = 1; i <= n; i++)
        if (V[i] == 2)
        {
            if (--x > 0) g << i << ",";
            else g << i;
        }
    g << '}';
    g.close();
    return 0;
}
