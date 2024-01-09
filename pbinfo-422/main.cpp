#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

int n , a[105][105], g[105];

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
	
	int gmax = -1;
	
    for(int i = 1 ; i <= n ; ++i)
    {
		g[i] = 0;
        for(int j = 1 ; j <= n ; j++)
            if(a[i][j] == 1)
				g[i] ++;
		if(g[i] > gmax)
			gmax = g[i];
	}
	int melim = 0;
	for(int i=1;i<=n;++i)
		if(g[i] == gmax)
			for(int j = 1 ; j <= n ; ++j)
					if(a[i][j] == 1)
						melim ++, a[i][j] = a[j][i] = 0;
	
	
	fout << melim << "
";
    for(int i = 1 ; i <= n ; ++i)
    {
		for(int j = 1 ; j <= n ; j++)
			fout << a[i][j] <<" ";
		fout << "
";
	}

    return 0;
}
