#include <iostream>

using namespace std;

int main() {
	
	int n, d = 2;
	
	cin >> n;
	
	while(n % d != 0)
		d ++;
	
	
	cout << d + n / d << endl;
	
    return 0;
}
