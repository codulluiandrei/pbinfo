#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;

ifstream fin("zapada.in");
ofstream fout("zapada.out");

struct muchie{
	int obl , i , j , cost;
};

int n , m , t[105];

muchie x[5000];

int main()
{
    fin >> n >> m;
    
    for(int i = 0 ; i < m ; ++i)
		fin >> x[i].i >> x[i].j >> x[i].cost;
	int k;
	fin >> k;
	for( ; k ; --k)
	{
		int i;
		fin >> i;
		x[i - 1].obl = 1;
	}
	for(int i = 0 ; i < m - 1; i ++)
		for(int j = i + 1 ; j < m ; ++j)
			if(x[i].obl < x[j].obl)
			{
				muchie aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
			else
				if(x[i].obl == x[j].obl)
					if(x[i].cost > x[j].cost)
					{
						muchie aux = x[i];
						x[i] = x[j];
						x[j] = aux;
					}
	for(int i =1 ; i <= n ; ++i)
		t[i] = i;
	int S = 0;
		
	for(int i = 0 ; i < m ; i ++)
		if(x[i].obl == 1 || t[x[i].i] != t[x[i].j])
		{
			S += x[i].cost;
			if(t[x[i].i] != t[x[i].j])
			{
				int ai = t[x[i].i], aj = t[x[i].j];
				for(int j =1 ; j <= n ; ++j)
					if(t[j] == aj)
						t[j] = ai;
			}
		}
	fout << S << "
";
	return 0;
}
