#include <iostream>
using namespace std;

int n, d[100000], T;

int main(){
	cin  >> n >> T;
	for(int i =1 ; i <= n ; ++i)
		cin >> d[i];
	int c = 0;
	for(int i =1; i <= n ; ++i)
		c += T / d[i];
	cout << c;
	
	return 0;
}
