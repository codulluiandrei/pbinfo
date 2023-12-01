#include <iostream>
#include <cassert>
using namespace std;

int main(){
	int n,x, d2 = 0, d5 = 0, p=1;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> x;
		while(x%2==0)
			d2++, x/=2;
		while(x%5==0)
			d5++, x/=5;
		p = (p * (x%10)) %10;
	}
	int k = 0 , f = 0;
	if(d2>d5)
		k = d2 - d5, f = 2;
	else
		k = d5 - d2, f = 5;
	while (k>0)
		p  = (p*f)%10 , k--;
	cout << p;
	return 0;
}
