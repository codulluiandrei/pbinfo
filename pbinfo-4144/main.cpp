#include <fstream>
using namespace std;

ifstream in("graffiti.in");
ofstream out("graffiti.out");

const int N = 1e5;
const int Log = 17;

long long S[N + 1];
int rmq[Log + 1][N + 1], lg2[N + 1];

int main()
{
    

    int n, m, L, x, y;
    in >> n;
    
    for (int i = 1; i <= n; i++)
    {
        in >> L >> rmq[0][i];
        S[i] = S[i - 1] + L;
    }

    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= Log; i++)
        for (int j = 1; j + (1 << (i - 1)) - 1 <= n; j++)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);

    in >> m;
    while (m--)
    {
        in >> x >> y;
        int l_lg = lg2[y - x + 1];
        out << (S[y] - S[x - 1]) * min(rmq[l_lg][x], rmq[l_lg][y - (1 << l_lg) + 1]) << '\n';
    }

    in.close();
    out.close();

    return 0;
}

