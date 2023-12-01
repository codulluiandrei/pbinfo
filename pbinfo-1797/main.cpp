#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 3 < 2)
        cout << 2 * (n / 3);
    else
        cout << 2 * (n / 3) + 1;
    return 0;
}
