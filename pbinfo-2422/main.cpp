#include <iostream>
#include <fstream>

using namespace std;
ifstream f("produsmaxim.in");
ofstream g("produsmaxim.out");
int X, a, b, c;
int main()
{
    while (f >> X)
        if (X % 3 == 0) g << X << ' ' << X / 3 << ' ' << X / 3 << ' ' << X / 3 << '\n';
                else if (X % 3 == 1) g << X << ' ' << X / 3 << ' ' << X / 3 << ' ' << X / 3 + 1 << '\n';
                    else g << X << ' ' << X / 3 << ' ' << X / 3 + 1 << ' ' << X / 3 + 1 << '\n';
    return 0;
}
