#include <iostream>
using namespace std;
int A[1005], B[1005], n, t1, t2;
int main(){
	cin  >> n >> t1 >> t2;
	for(int i = 0 ; i < n ; ++i)
		cin >> A[i] >> B[i];
	for(int i = 0; i < n - 1 ; i ++ )
		for(int j = i + 1; j < n ; ++j)
			if(A[i]>A[j])
			{
				int aux = A[i]; A[i] = A[j]; A[j] = aux;
				aux = B[i]; B[i] = B[j]; B[j] = aux;
			}
			else
				if(A[i] == A[j])
					if(B[i] > B[j])
					{
						int aux = B[i]; B[i] = B[j]; B[j] = aux;
					}
	int s = A[0] - t1;
	int p = A[0], q = B[0];
	for(int i = 1 ; i < n ; ++i)
	{
		if(A[i] <q)
		{
		    if(B[i] > q)
                q = B[i];
		}
		else
		{
			s += A[i] - q;
			p = A[i], q = B[i];
		}
	}
	s += t2 - q;
	cout << s;
	return 0;
}