#include <iostream>
using namespace std;
int n , x[41], cnt;
void Afisare(int k)
{
	for(int i =1 ; i <= k ; i ++)
		cout << x[i] << " ";
	cout << endl;
}
void Back(int k , int S)
{
	for(int i = x[k-1] + 2; i <= n ; i += 2)
	{
		x[k] = i;
		if(S + x[k] <= n)
		{
			if(S + x[k] == n)
				Afisare(k), cnt ++;
			else
				Back(k + 1 , S + x[k]);
		}
	}
}
int main()
{
	cin >> n;
	x[0] = -1;
	Back(1 , 0);
	if(cnt == 0)
		cout << "imposibil\n";
	return 0;
}