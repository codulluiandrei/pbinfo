#include <fstream>
using namespace std;
ifstream in("conflicte.in");
ofstream out("conflicte.out");
int alianta(int x)
{
    int a = 0;
    while (x)
    {
        a |= (1 << x % 10);
        x /= 10;
    }
    return a;
}
int main()
{
    int T, Q, f[(1 << 10)] = { 0 }, q[1000], x;
    in >> T;
    if (T == 2)
    {
        in >> Q;
        for (int i = 0; i < Q; i++)
        {
            in >> x;
            q[i]=alianta(x);
        }
    }
    while (in >> x) f[alianta(x)]++;
    if (T == 1)
    {
        int cnt = 0;
        for (int i = 1; i < 1 << 10; i++)
        {
            if (f[i] == 1)
                cnt++;
        }
        out << cnt;
    }
    else
    {
         for (int i = 0; i < Q; i++)
        {
            int sum = 0;
            for (int b = 1; b < 1 << 10; b++)
                if ((b & q[i]) == 0)
                    sum += f[b];
            out << f[q[i]] - 1 << ' ' << sum << '\n';
        }    
    }
    return 0;}