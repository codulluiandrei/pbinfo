#include <iostream>
using namespace std;
long long n;
int runde;
int main()
{
    /// Observam ca, pentru a putea realiza campionatul, n trebuie sa fie o putere a lui 2.
    cin >> n;
    while (n % 2 == 0)
        n /= 2, ++runde;
    if (n != 1)
        cout << -1;
    else
        cout << runde;
    return 0;
}