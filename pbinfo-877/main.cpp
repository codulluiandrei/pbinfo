#include <iostream>
using namespace std;
int n , nrS, S[1005] , v[10005];
int main()
{
	cin >> n;
	for(int i =1 ; i <= n ; i ++)
		cin >> v[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		while(nrS > 0 && v[S[nrS]] < v[i])
			nrS --;
		S[++nrS] = i;
	}
	cout << nrS << "\n";
	for(int i = 1 ; i <= nrS ; i ++)
		cout << S[i] << " ";
	return 0;
}