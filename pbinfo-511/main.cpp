#include <iostream>
using namespace std;

int main(){
	int n , k, x[1005];
	cin  >> n >> k;	
	for(int i = 0 ; i < n ; ++ i)
		cin >> x[i];
	bool sortat = false;
	while(! sortat)
	{
		sortat = true;
		for(int i = 0 ; i < k - 1 ; i++)
			if(x[i] > x[i+1])
			{
				int aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
				sortat = false;
			}
	}
	sortat = false;
	while(! sortat)
	{
		sortat = true;
		for(int i = k ; i < n - 1 ; i++)
			if(x[i] < x[i+1])
			{
				int aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
				sortat = false;
			}
	}
	for(int i = 0 ; i < n ; ++ i)
		cout << x[i] << " ";
	return 0;
}
