#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cautafibo.in");
ofstream fout("cautafibo.out");
long long f[47], x, i, k, OK, li, ls, m;
int main()
{
    f[1] = 1;
    f[2] = 2;
    for (i = 3; i <= 46; i++)
        f[i] = f[i - 1] + f[i - 2];
    k = 0;
    while (fin >> x)
    {
        li = 1;
        ls = 46;
        OK = 0;
        while (li <= ls && !OK)
        {
            m = (li + ls) / 2;
            if (x == f[m]) OK = 1;
            else if (x < f[m]) ls = m - 1;
                    else li = m + 1;
        }
        k += OK;
    }
    fout << k;
    return 0;
}