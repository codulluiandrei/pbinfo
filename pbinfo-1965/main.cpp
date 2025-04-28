/// solutie - Moca Andrei - 100p
#include <iostream>
using namespace std;
int a[27][3000], j, n, k, c, p;
int main()
{
	cin >> n;
	a[1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		j = 1;
		k = 0;
		while(a[i-1][j])
		{
			p = 0;
			c = a[i - 1][j];
			while(a[i-1][j] == c && a[i-1][j])
				j++, p++;
			k++;
			a[i][k] = c;
			k++;
		    a[i][k] = p;
		}
	}
	j = 1;
	while(a[n][j])
        j++;
    for (int i = j - 1; i > 0; i--)
        cout << a[n][i];
	return 0;
}