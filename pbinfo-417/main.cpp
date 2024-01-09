#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("gradmax.in");
ofstream fout("gradmax.out");

int n , a[105][105], g[105];

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }

    for(int i = 1 ;  i <= n ; i++){
        g[i] = 0;
        for(int j = 1; j <= n ; ++j)
            if(a[i][j] == 1)
                g[i] ++;
    }

    for(int i = 1 ;  i <= n ; i++)
        cout << g[i] << " ";

    int gmax = 0 , nrv = 1;
    for(int i = 1 ;  i <= n ; i++)
        if(g[i] > gmax)
            gmax = g[i], nrv = 1;
        else
            if(g[i] == gmax)
                nrv ++;

    fout << nrv << " ";
    for(int i = 1 ;  i <= n ; i++)
        if(g[i] == gmax)
            fout << i << " ";

    return 0;
}
