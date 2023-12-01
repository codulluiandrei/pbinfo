#include <iostream>

using namespace std;

int main(){
	int n, A[1001];
    
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> A[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		int pp = true;
		if(A[i] < 2)
			pp = false;
		for(int d = 2 ; d * d <= A[i] ; d ++)
			if(A[i] % d == 0)
				pp = false;
		if(pp)
			A[i] = 0;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		cout << A[i] << " ";
		
    return 0;
}
