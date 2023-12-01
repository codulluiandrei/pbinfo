#include <fstream>

using namespace std;

ifstream fin("vapoare.in");
ofstream fout("vapoare.out");

long long x, y, z1, z2, xy;

int main()
{
    fin >> x >> y;
    fin >> z1 >> z2;
    x = x*14+z1;
    y = y*14+z2;
    xy=x*y;
    while(x!=y)
        if(x>y)
            x=x-y;
        else
            y=y-x;
    fout << xy / x;

    return 0;
}
