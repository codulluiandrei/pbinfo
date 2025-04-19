#include <fstream>
using namespace std;
int main()
{
    int r, n, i, s;
    ifstream f("sir10.in");
    ofstream g("sir10.out");
    s = 0;
    f >> n;
    for (r = 1; r <= n / 2; r++)
    {
        i = n - 2 * r;
        while (i > 0)
        {
            s += i;
            i -= r;
        }
    }
    g << s << "\n";
    g.close();
    return 0;
}