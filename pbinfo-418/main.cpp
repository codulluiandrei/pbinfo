#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("subgraf.in");
ofstream fout("subgraf.out");
int n , a[105][105];
bool prim(int n){
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int d = 3 ; d * d <= n ; d += 2)
        if( n % d == 0 )
            return false;
    return true;
}
int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
    for(int i = 1 ; i <= n ; ++ i)
        if(prim(i))
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