#include <iostream>
using namespace std;
int n;
int V[100001];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> V[i];
	int max1 = V[1], max2 = V[2];
	if(max1 < max2)
	{
		int aux = max1;
		max1 = max2;
		max2 = aux;
	}
	for(int i = 3; i <= n; i++)
		if(V[i] > max1)
			max2 = max1, max1 = V[i];
		else
			if(V[i] > max2)
				max2 = V[i];
	int min1 = V[1], min2 = V[2];
	if(min1 > min2)
	{
			int aux = min1;
			min1 = min2;
			min2 = aux;
	}
	for(int i = 3; i <= n; i++)
		if(V[i] < min1)
			min2 = min1, min1 = V[i];
		else
			if(V[i] < min2)
				min2 = V[i];
	long long int P1 = 1LL * min1 * min2, P2 = (long long)max1 * max2;
	if(P1 > P2)
		cout << P1 << "\n";
	else
		cout << P2 << "\n";
}