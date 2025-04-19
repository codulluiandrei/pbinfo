#include <iostream>
using namespace std;
int main(){
	int n, x[1005];
	cin  >> n;	
	for(int i = 0 ; i < n ; ++ i)
		cin >> x[i];
	bool ok = true;
	for(int i = 0 ; i < n - 1 ; i++ )
		if(x[i] * x[i + 1] == 1)
			ok = false;
	if(ok)
		cout << "DA";
	else
		cout << "NU";
	return 0;
}