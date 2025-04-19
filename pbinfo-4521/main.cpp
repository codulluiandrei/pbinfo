#include <iostream>
using namespace std;
int main()
{
	int n, max = -1;
    cin >> n;
    int a, b, x;
    a = n % 10, b = n / 10 % 10;
    x = a * 10 + b;
    if(x > max)
        max = x;
    x = b * 10 + a;
    if(x > max)
        max = x;
    n /= 10;
    a = n % 10, b = n / 10 % 10;
    x = a * 10 + b;
    if(x > max)
        max = x;
    x = b * 10 + a;
    if(x > max)
        max = x;
    n /= 10;
    a = n % 10, b = n / 10 % 10;
    x = a * 10 + b;
    if(x > max)
        max = x;
    x = b * 10 + a;
    if(x > max)
        max = x;
    n /= 10;
    cout << max;
}