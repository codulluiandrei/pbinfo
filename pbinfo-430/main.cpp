#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

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

    int nrv = 0;
    for(int i = 1 ;  i <= n ; i++)
        if(g[i] == 0)
                nrv ++;

    fout << nrv << " ";
    for(int i = 1 ;  i <= n ; i++)
        if(g[i] == 0)
            fout << i << " ";

    return 0;
}
