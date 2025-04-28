/// Sursa Vasiluta Mihai-Alexandru
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("polybius.in");
ofstream g("polybius.out");
char c, d, w[8][8];
int v[128], i, j, p;
int main()
{
    f >> p;
    if(p == 1)
    {
        for(i = 1; i <= 5; i++)
            for(j = 1; j <= 5; j++)
            {
                f >> c;
                v[int(c)] = i * 10 + j;
            }
        while(f >> c)
            g << v[int(c)];
    } else
    {
        for(i = 1; i <= 5; i++)
            for(j = 1; j <= 5; j++)
                f >> w[i][j];
        while(f >> c >> d)
            g << w[int(c - '0')][int(d - '0')];
    }
    return 0;
}