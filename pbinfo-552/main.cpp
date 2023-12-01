#include <iostream>
using namespace std;

int A[2005], B[2005], n;

// A[i] - necesar
// B[i] - existent

int main(){
	cin  >> n;	
	for(int i = 1 ; i <= n ; ++i)
		cin >> A[i] >> B[i];
	for(int i = 1 ; i <= n ; ++i)
		A[n+i] = A[i], B[n+i] = B[i];
	
	int p = -1;
	for(int i = 1; i <= n && p == -1 ; i ++)
	{
		int s = 0;
		bool OK = true;
		for(int j = 0; j < n && OK ; ++j)
		{
			s += B[i+j];
			s -= A[i+j];
			if(s < 0)
				OK = false;
		}
		if(OK)
			p = i;
	}
	cout << p ;
	
	return 0;
}
