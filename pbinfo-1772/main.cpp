/// solutie - Moca Andrei - 100p
#include <iostream>
using namespace std;
int main()
{
    int a, n, ratie;
    cin >> a >> ratie >> n;
    for (int i = 1; i <= n; i++, cout << '\n', a += ratie)
        for (int j = 1; j <= n; j++)
            cout << a + ((ratie * n) * (j - 1)) << " ";
}