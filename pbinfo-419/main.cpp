#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");

int n , a[105][105], g[105];

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }

    for(int i = 1 ; i <= n ; ++ i){
        g[i] = 0;
        for(int j = 1 ; j <= n ; ++ j)
            if(a[i][j] == 1)
                g[i] ++;
    }

    int gmin = n+1;
    for(int i = 1 ; i <= n ; ++ i)
        if(g[i] < gmin)
            gmin = g[i];

    for(int i = 1 ; i <= n ; ++ i)
        if(g[i] == gmin)
            for(int j = 1 ; j <= n ; ++ j)
                a[i][j] = a[j][i] = 0;

    int nrm = 0;
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = i + 1; j <= n; ++ j)
            if(a[i][j] == 1)
                nrm ++;

    fout << nrm;

    return 0;
}
