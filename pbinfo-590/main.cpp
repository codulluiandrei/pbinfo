#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");
int n , a[105][105], v[105], d[105], t[105];
int main()
{
    int i , j , c , m;
    fin >> n >> m;
    for(i =1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j)
			a[i][j] = INFINIT;
		a[i][i] = 0;
	}
    while( m )
    {
		fin >> i >> j >> c;
    	a[j][i] = a[i][j] = c;
    	m --;
	}
	for(i =1 ; i <= n ; i ++ )
	{
		v[i] = 0;
		d[i] = a[1][i];
		t[i] = 1;
	}
	v[1] = 1; // vectorul de vizitati
	t[1] = 0; //vectorul de tati
	d[1] = 0; // vectorul cu costurile 
	d[0] = INFINIT;
	for(int k = 1 ; k < n ; ++k)
	{
		int pmax = 0;
		// alegem un varful nevizitat care se leaga de arborele curent cu cost minim
		for(i = 1 ; i <= n ; ++i)
			if(v[i] == 0 && d[i] < d[pmax])
				pmax = i;
		if(pmax > -1)
		{
			v[pmax] = 1;
			// verificam daca varful adaugat in arbore nu imbunatateste costurile de legare la arbore a varfurilor inca nevizitate
			for(i = 1; i <= n ; ++i)
				if(v[i] == 0 && d[i] > a[pmax][i])
					d[i] = a[pmax][i], t[i] = pmax;
		}
	}
	int S = 0;
	for(i = 1 ; i <= n ; ++i)
		S += d[i];	
	fout << S << endl;
	for(i = 1 ; i <= n ; ++i)
		fout << t[i] << " ";
    return 0;
}