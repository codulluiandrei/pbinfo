#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("gradek.in");
ofstream fout("gradek.out");
int n , a[105][105], g[105], k;
int main()
{
    int i , j;
    fin >> n >> k;
    while(fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        g[i] = 0;
        for(int j = 1; j <= n; ++j)
            if(a[i][j] == 1)
                g[i] ++;
    }
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(g[i] == g[k])
			cnt ++;
	fout << cnt << '\n';
    for(int i = 1; i <= n; i++)
		if(g[i] == g[k])
			fout << i << " ";
	fout << '\n';
    return 0;
}