#include <iostream>
using namespace std;
int main(){
	int n, a , b , C = 0, x, sx , y , sy;
	cin >> n >> a;
	for(int i = 2 ; i <= n ; ++i){
		cin >> b;
		x = a; y = b;
		sx = sy = 0;
		while(x)
			sx += x % 10, x /= 10;
		while(y)
			sy += y % 10, y /= 10;
		if(sx%2 != sy%2)
			C++;
		a = b;
	}
	cout << C;
	return 0;
}