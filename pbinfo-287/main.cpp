#include <iostream>
#include <cassert>

using namespace std;

int n,m,a[501];

int main(){
	cin >> n;;
	for( ; n ; --n){
		assert(cin >> m);
		for(int i=1 ; i<=m ; ++i)
			assert(cin >> a[i]);
		int pp = 1;
		for(int i=2 ; i<=m ; ++i)
			if(a[i]<a[i-1])
				pp = 0;
		cout << pp << " ";
	}
	return 0;
}
