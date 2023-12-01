#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    for (int i = 1; i<= N; i++)
    {
        unsigned long long x; cin  >> x;
        cout << x%7 << '\n';
    }
    return 0;
}
