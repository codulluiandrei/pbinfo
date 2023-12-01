#include <iostream>
#include <cassert>

using namespace std;

int n,a[101],b[101];

int main(){
	cin >> n;
	for(int i=1 ; i<=n ; ++i){
		assert(cin >> a[i]);
		assert(a[i]<10000);
	}
	for(int i=1 ; i<=n ; ++i){
		assert(cin >> b[i]);
		assert(b[i]<10000);
	}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i]>a[j]){
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	for(int i=2;i<=n;++i){
		int x = b[i];
		int j=i;
		while(j>1 && b[j-1]>x){
			b[j] = b[j-1];
			j--;
		}
		b[j] = x;
	}
	int pp = 1;
	for(int i=2 ; i<=n ; ++i){
		if(a[1]*b[i]!=b[1]*a[i])
			pp = 0;
	}
	if(pp)
		cout << "DA";
	else
		cout << "NU";
	return 0;
}
