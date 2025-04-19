#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d;
    x = (a > c ? a : c);
    y = (b < d ? b : d);
    if (x > y) x = y = -1;
    cout << x << " " << y;
    return 0;
}