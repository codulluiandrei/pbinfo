#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n, delta, rasp;
    cin >> n;
    delta = 1 + 8 * (n - 1);
    rasp = (1 + sqrt(delta)) / 2;
    cout << rasp;
    return 0;
}
/// Rezolvare folosind formula matematica