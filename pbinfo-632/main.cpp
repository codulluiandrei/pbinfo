#include <iostream>
using namespace std;
int v[105], n, p;
int main(){
	cin >> n >> p;
	for(int i =1 ; i <= n ; ++i)
		v[i] = i, p -= i;
	for(int i =1 ; i <= n ; ++i)
		v[i] += p/n;
	if(p % n != 0)
	{
		int k = p % n;
		for(int i = n ; i > 0 && k ; i --)
			v[i] ++, k --;
	}
	for(int i = 1 ; i <= n ; ++i)
		cout << v[i] << " ";
	return 0;
}