#include <iostream>
#include <iomanip>
using namespace std;


int n , S, v[10], x[10], c[100], gasit = false;

void Afis(int k)
{
	gasit = true;
	for(int i = 1 ; i <= k ; i ++)
		cout << x[i] << " ";
	cout << "
";
}

void back(int k, int sum)
{
	if(k <= n)
		for(int i = 0 ; i <= min((S - sum) / v[k], c[k]) && !gasit ; i ++)
		{
			x[k] = i;
			if(sum + x[k] * v[k] == S)
				Afis(k);
			else
				back(k + 1 , sum + x[k] * v[k]);
		}
}

int main()
{
	cin >> n >> S;
	for(int i = 1 ; i <= n ; ++i)
		cin >> v[i];
	for(int i = 1 ; i <= n ; ++i)
		cin >> c[i];
    back(1, 0);
	return 0;
}

