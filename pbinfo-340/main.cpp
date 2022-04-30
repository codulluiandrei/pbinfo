#include <iostream>
using namespace std;
int main() {
	long long int n;
    cin >> n;
    if (n % 9 == 0)
    	cout << 9;
    else cout << n % 9;
    return 0;
}
