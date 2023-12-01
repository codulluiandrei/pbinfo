#include <iostream>

using namespace std;

int main(){
	int n, A[1001];
    
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> A[i];
	
	int Min = A[1];
	for(int i = 2 ; i <= n ; i ++)
		if(A[i] < Min)
			Min = A[i];
			
	
	for(int i = n ; i >= 1; i --)
		if(A[i] == Min)
		{
			for(int j = i ; j < n ; j ++)
				A[j] = A[j+1];
			n --;
		}
	
	for(int i = 1 ; i <= n ; i ++)
		cout << A[i] << " ";
		
    return 0;
}
