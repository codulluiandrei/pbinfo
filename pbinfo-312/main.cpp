#include <iostream>
#include <cassert>
using namespace std;

int v[1000000];

int main(){
	int n,x;
	cin >> x >> n;
	v[v[0]=1]=1;
	for(int k=1;k<=n;++k){
		int t = 0;
		for(int i=1;i<=v[0];++i){
			int aux = v[i]*x + t;
			v[i] = aux %10;
			t = aux/10;
		}
		while(t){
			v[++v[0]] = t%10;
			t /= 10;
		}
	}
	for(int i = v[0] ; i>0 ; --i)
		cout << v[i];
	return 0;
}
