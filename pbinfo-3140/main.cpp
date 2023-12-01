/// Sursa Vasiluta Mihai-Alexandru
#include <fstream>
using namespace std;
ifstream f("a1z26.in");
ofstream g("a1z26.out");
char c;
int p, n, i, k;

int main()
{
    f >> p;
    if(p == 1)
    {
        while(f >> c)
            g << c - 'A' + 1 << " ";
    } else
    {
        f >> n;
        for(i = 1; i <= n; i++)
        {
            f >> k;
            g << char(k + 'A' - 1);
        }
    }
    return 0;
}
