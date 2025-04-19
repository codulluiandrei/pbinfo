#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, nr;
    cin >> a >> b >> c >> d;
    nr = d / 3 - (c - 1) / 3 + b / 3 - (a - 1) / 3;
    cout << nr;
    return 0;
}