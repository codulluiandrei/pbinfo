#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("graf_partial_1.in");
ofstream fout("graf_partial_1.out");

int n , a[105][105], g[105];

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
	
	int gmin = n+1, gmax = -1;
	
    for(int i = 1 ; i <= n ; ++i)
    {
		g[i] = 0;
        for(int j = 1 ; j <= n ; j++)
            if(a[i][j] == 1)
				g[i] ++;
		if(g[i] > gmax)
			gmax = g[i];
		if(g[i] < gmin)
			gmin = g[i];
	}
	int melim = 0;
	for(int i=1;i<=n;++i)
		if(g[i] == gmin)
			for(int j = 1 ; j <= n ; ++j)
				if(g[j] == gmax)
					if(a[i][j] == 1)
						melim ++, a[i][j] = a[j][i] = 0;
	fout << melim << "
";
	for(int i = 1 ; i <= n ; ++i)
		cout << g[i] << " ";
	
	
	
    for(int i = 1 ; i <= n ; ++i)
    {
		for(int j = 1 ; j <= n ; j++)
			fout << a[i][j] <<" ";
		fout << "
";
	}

    return 0;
}
