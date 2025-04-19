#include <bits/stdc++.h>
using namespace std;
#define N 101
int v1[N],v2[N];
int main()
{
	char sir1[N], sir2[N];
	int n;
	cin >> sir1>>sir2;
	n = strlen(sir1);
	if (n != strlen(sir2))
	{
		cout << "NU SUNT PRIETENE";
		return 0;
	}
	for (int i = 0; i<n; i+=2)
    {
		v1[sir1[i] - 'a']++;
		v2[sir2[i] - 'a']++;
    }
	for(int i=0;i<n;i++)
        if (v1[i] != v2[i])
		{
			cout << "NU SUNT PRIETENE";
			return 0;
		}
	for (int i = 1; i<n; i += 2)
    {
		v1[sir1[i] - 'a']++;
		v2[sir2[i] - 'a']++;
    }
	for (int i = 0; i < n; i++)
		if (v1[i] != v2[i])
		{
			cout << "NU SUNT PRIETENE";
			return 0;
		}
	cout << "PRIETENE";
	return 0;
}