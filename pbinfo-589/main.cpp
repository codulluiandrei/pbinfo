#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;

ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");

int n , a[105][105];

int main()
{
    int m;
    fin >> n >> m;
    
    for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j)
			a[i][j] = INFINIT;
		a[i][i] = 0;
	}
	
    while( m )
    {
		int i , j , c;
		fin >> i >> j >> c ;
    	a[i][j] = c;
    	m --;
	}
	
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
	
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			fout << (a[i][j] == INFINIT ? -1 : a[i][j]) << " ";
		fout << endl;
	}
	
    return 0;
}
