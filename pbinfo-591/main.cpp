#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;

ifstream fin("firma.in");
ofstream fout("firma.out");

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
    	a[i][j] = a[j][i] = c;
    	m --;
	}
	
	for(int k = 1 ; k <= n ; ++k)
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				if(a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
	
	/*
	for(int i =1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
			cerr << a[i][j] << " ";
		cerr << endl;
	}
	*/
	
	int pmin =0, smin = INFINIT;
	for(int i = 1 ; i <= n ; ++i)
	{
		int s = 0;
		for(int j = 1 ; j <= n ; ++j)
			s += a[i][j];
		//cerr << s << endl;
		if(s < smin)
			smin = s, pmin = i;
	}
	fout << pmin << endl;
    return 0;
}
