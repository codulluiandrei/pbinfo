#include <iostream>
#include <fstream>

using namespace std;
ifstream f("secventaincadrata.in");
ofstream g("secventaincadrata.out");
int ap1[10], ap2[10], n, i, x, k, lmax;
int main()
{
    n = 0;
    while (f >> x)
    {
        n++;
        if (ap1[x] == 0) ap1[x] = n;
        else ap2[x] = n;
    }
    lmax = 0;
    for (i = 0; i <= 9; i++)
        if (ap2[i] - ap1[i] + 1 > lmax) lmax = ap2[i] - ap1[i] + 1;
    g << lmax <<'\n';
    for (i = 0; i <= 9; i++)
        if (ap2[i] - ap1[i] + 1 == lmax) g << i <<' ';
    return 0;
}
