#include <iostream>
using namespace std;
int n , x;
int main(){
	while(cin >> n){
		x = 0;
		while (n>x)
			n -= x, x++;
		if(n==0)
			cout << 1 << endl;
		else
			cout << x-n+1 << endl;
	}
	return 0;
}