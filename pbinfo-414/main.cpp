#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("listavecini.in");
ofstream fout("listavecini.out");

int n , a[105][105];

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }

    for(int i = 1 ;  i <= n ; i++){
        int nrv = 0;
        for(int j = 1; j <= n ; ++j)
            if(a[i][j] == 1)
                nrv ++;
        fout << nrv << " ";
        for(int j = 1; j <= n ; ++j)
            if(a[i][j] == 1)
                fout << j << " ";
        fout << "
";
    }
    return 0;
}
