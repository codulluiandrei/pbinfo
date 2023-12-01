//Pereche


#include <iostream>
#include <cstdlib>
using namespace std;

int n, H[1005];

int main(){
	cin  >> n;
	for(int i =1 ; i <= n ; ++i)
		cin >> H[i];
	int difmin = abs(H[n] - H[1]), i1 = 1, i2 = n;
	for(int i = 1 ; i < n ; ++i)
	{
		int difc = abs(H[i] - H[i+1]);
		if(difc < difmin)
			difmin = difc, i1 = i , i2 = i + 1;
	}
	cout << i1 << " " << i2;
	return 0;
}
