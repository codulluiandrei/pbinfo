#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
    cout << (n-1)*n*(n+1)/6 + n + 1;
    return 0;
}