#include <iostream>
using namespace std;

int main(){
	int x;
	cin >> x;
	while(x > 1)
	{
		cout << x << " ";
		if(x % 2 == 1)
			x = x / 2 + 1;
		else
			x --;
	}
	cout << 1;
	return 0;
}
