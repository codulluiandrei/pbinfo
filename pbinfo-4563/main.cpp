#include <iostream>
using namespace std;
int main()
{
    int n;
    long long S = 0;
    cin >> n;
    while(n != 0)
    {
        if(n % 2 == 0)
            S += n;
        n /= 10;
    }
    cout << S;
    return 0;
}