#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("sumaoni.in");
ofstream fout("sumaoni.out");
void Sol(int n, int i)
{
    fout << n << "\n";
    if (i > 0)
    {
        while (i > 0)
            if (i <= n)
            {
                fout << i << "\n";
                i = 0;
            }
            else
            {
                fout << n << "\n";
                i -= n;
                n--;
            }
    }
}
int main()
{
    int s, n, d;
    fin >> s;
    n = (sqrt(1 + 8 * s) - 1) / 2;
    if ((n * (n + 1)) / 2 < s)
        n++;
    d = (n * (n + 1)) / 2 - s;
    if (d % 2 == 0) Sol(n, d / 2);
    else
    {
        n++;
        d = (n * (n + 1)) / 2 - s;
        if (d % 2 == 0) Sol(n, d / 2);
        else
        {
            n++;
            d = (n * (n + 1)) / 2 - s;
            Sol(n, d / 2);
        }
    }
    fin.close();
    fout.close();
    return 0;
}