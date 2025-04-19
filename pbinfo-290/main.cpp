#include <iostream>
#include <cassert>
using namespace std;
int n,m,a[101];
int main(){
	cin >> n;;
	for(int i=1 ; i<=n ; ++i)
		assert(cin >> a[i]);
	int pp = 1, k=0;
	for(int i=1 ; i<=n ; ++i)
		if(a[i]%2 == 0)
			if(k==0)
				k = i;
			else{
				if(a[i]<a[k])
					pp = 0;
				k = i;
			}
	if(pp)
		cout << "DA";
	else
		cout << "NU";
	return 0;
}