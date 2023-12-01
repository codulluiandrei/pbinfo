#include <iostream>
using namespace std;

int munte(int x){
	int n=0,v[15];
	while(x){
		v[++n]=x%10;
		x /= 10;
	}
	for(int i=1,j=n;i<j;++i, --j){
		int aux = v[i];
		v[i] = v[j];
		v[j] = aux;
	}
	int i=2;
	while(i <=n && v[i-1]<v[i] )
		i++;
	if(i==2 || i>n)
		return 0;
	while(i <=n && v[i-1]>v[i] )
		i++;
	if(i>n)
		return 1;
	return 0;
}

int main(){
	int n,x;
	cin >> n;
	for( ; n  ; --n){
		cin >> x;
		cout << munte(x) << endl;
	}
	return 0;
}
