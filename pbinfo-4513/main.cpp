#include <iostream>
using namespace std;
int main()
{
	int n;
    cin >> n;
    if(n < 10)
        cout << n * n;
    else
        if(n < 100)
        	cout << n/10 + n%10;
        else
        	cout << n / 10 % 10;
    return 0;
}