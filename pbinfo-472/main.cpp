#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
ifstream fin("bipartit1.in");
ofstream fout("bipartit1.out");
int n , a[20][20], x[20] , gasit = 0;
void verif()
{
	for(int i = 1 ; i <= n ; ++ i)
		for( int j = 1 ; j <= n ; ++ j)
			if( a[i][j] != 0 )
				a[i][j] = 1;
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j <= n ; ++j)
			if(x[i] != x[j])
				if(a[i][j] != 0)
					a[i][j] = a[j][i] = 2;
	int  cnt = 0;
	for(int i = 1 ; i < n ; ++i)
		for(int  j = i + 1 ; j <= n ; ++j)
			if(a[i][j] == 1)
				cnt ++;
	if(cnt == 0){
		fout << "DA
";
		int p=0, q = 1;
		if(x[1] == 1)
			p = 1, q = 0;
		for(int i =1 ; i <= n ; ++i)
			if(x[i] == p)
				fout << i << " ";
		fout << "\n";
		for(int i =1 ; i <= n ; ++i)
			if(x[i] == q)
				fout << i << " ";
		fout << "\n";
		gasit = 1;
	}
}
void back(int k)
{
	for(int  i = 0 ; i < 2 && !gasit ; ++i)
	{
		x[k] = i;
		if(k==n)
			verif();
		else
			back(k+1);
	}
}
int main()
{
    int i , j , m;
    fin >> n >> m;
    while(m > 0)
    {
		fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
    	m --;
    }
    back(1);
    if( !gasit )
		fout << "NU";
	return 0;
}