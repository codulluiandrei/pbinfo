#include <iostream>
#include <fstream>
#define INFINIT 1000000000
using namespace std;

ifstream fin("kruskal.in");
ofstream fout("kruskal.out");

struct muchie{
	int i,j,cost;
};

int n , m , t[105];

muchie x[5000];
int v[5000];

int main()
{
    fin >> n >> m;
    
    for(int i = 0 ; i < m ; ++i)
		fin >> x[i].i >> x[i].j >> x[i].cost;
	
	for(int i = 0 ; i < m - 1; i ++)
		for(int j = i + 1 ; j < m ; ++j)
			if(x[i].cost > x[j].cost)
			{
				muchie aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
	for(int i =1 ; i <= n ; ++i)
		t[i] = i;
	int S = 0, cnt = 0;
	for(int i = 0 ; i < m && cnt < n ; i ++)
		if(t[x[i].i] != t[x[i].j])
		{
			v[i] = 1;
			S += x[i].cost;
			int ai = t[x[i].i], aj = t[x[i].j];
			for(int j =1 ; j <= n ; ++j)
				if(t[j] == aj)
					t[j] = ai;
		}
	fout << S << "
";
	for(int i = 0 ; i < m ; ++i)
		if(v[i] == 1)
			fout << x[i].i << " " << x[i].j << "
";
    return 0;
}
