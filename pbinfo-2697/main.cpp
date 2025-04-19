#include <iostream>
using namespace std;
int main()
{
    int N;
    long long n;
    cin >> N;
    while (N--)
    {
        cin >> n;
        while (n % 2 == 0)
            n /= 2;
        cout << n << " ";
    }
    return 0;
}