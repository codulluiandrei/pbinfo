#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");

int n,a[105][105];

int main()
{
    int i , j;
    while(fin >> i >> j){
        a[i][j] = a[j][i] = 1;
        if(i > n)
        	n = i;
        if(j > n)
        	n = j;
    }
    
    for(int i = 1 ;  i <= n ; i++){
        for(int j = 1; j <= n ; ++j)
            fout << a[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
