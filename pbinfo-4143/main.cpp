#include <fstream>
using namespace std;

ifstream in("ghicitoare.in");
ofstream out("ghicitoare.out");

int main()
{
    int T, n, x, S, S1, p;

    in >> T;
    for (int t = 1; t <= T; ++t)
    {
        in >> n >> S;
        S1 = 0;
        for (int i = n/4*4; i <= n; ++i)
            S1 ^= i;
        out << (S ^ S1) << '\n';
    }
    
    in.close();
    out.close();

    return 0;
}
