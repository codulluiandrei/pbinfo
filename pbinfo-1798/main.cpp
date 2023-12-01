#include <iostream>
using namespace std;
int main()
{
    int x = 1, y = 1, c, n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        c = x + y;
        x = y;
        y = c;
    }
    cout << c;
    return 0;
}
