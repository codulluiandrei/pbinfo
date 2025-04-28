/*
    Autor problema: Traian Mihai Danciu
    Autor solutie: Stefan Dascalescu
    Timp: O(n)
    Memorie: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("3secv.in");
	ofstream fout("3secv.out");
	int t;
	fin >> t;
	for(; t; t--)
	{
		int n;
		fin >> n;
		// dist[i] = care e a i-a valoare distincta
		// lst[i] = unde a aparut ultima oara
		int dist[3];
		int lst[3];
		for(int i = 0; i <= 2; i++)
		{
			dist[i] = -1;
			lst[i] = -1;
		}
		int smallest = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int x;
			fin >> x;
			bool ok = 0;
			for(int j = 0; j <= 2; j++)
				if(dist[j] == x)
				{
					ok = 1;
					lst[j] = i;
				}
			if(ok == 0)
			{
				for(int j = 0; j <= 2; j++)
					if(dist[j] == -1)
					{
						dist[j] = x;
						lst[j] = i;
						ok = 1;
						break;
					}
				if(ok == 0)
				{
					int smallest_last = 0;
					for(int j = 1; j <= 2; j++)
						if(lst[j] < lst[smallest_last])
							smallest_last = j;
					smallest = lst[smallest_last];
					dist[smallest_last] = x;
					lst[smallest_last] = i;
					ok = 1;
				}
			}
			ans = max(ans, i - smallest);
		}
		fout << ans << '\n';
	}
	return 0;
}