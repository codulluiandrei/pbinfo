#include <iostream>
using namespace std;

int main()
{
    int x, y, z, cnt = 0, i, j, k;
    cin >> x >> y >> z;
    for (i = x; i <= 9; i++)
        for (j = 0; j <= 9; j++)
            for (k = 0; k <= 9; k++)
                if (z - j - k >= 0 && z - j - k <= 9)
                    cnt++;
    cout << cnt;
    return 0;
}
