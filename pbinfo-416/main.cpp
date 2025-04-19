#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("grade.in");
ofstream fout("grade.out");
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
        fout << g[i] << " ";
    return 0;
}