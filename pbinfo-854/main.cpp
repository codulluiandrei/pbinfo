#include <iostream>
using namespace std;

int main(){
	int n, x , k , nrp = 0;
	cin  >> n >> k;	
	for(int i = 1 ; i <= n ; ++ i)
	{
		cin >> x;
		if(x % 2 == 1)
			nrp ++;
	}
	if(nrp % k == 0)
		cout << nrp / k << endl;
	else
		cout << nrp / k + 1 << endl;
	return 0;
}
