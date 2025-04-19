#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("graf_partial.in");
ofstream fout("graf_partial.out");
int n , a[105][105];
int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
    for(int i = 1 ; i <= n ; ++i)
        for(int j=i+2 ; j <= n ; j+=2)
            a[i][j] = a[j][i] = 0;
    int nrm = 0;
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = i + 1; j <= n; ++ j)
            if(a[i][j] == 1)
                nrm ++;
    fout << nrm;
    return 0;
}