#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lant1.in");
ofstream fout("lant1.out");
int n , p , q , r , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105], // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
	t[105]; // vectorul de tati
int sol[205], nsol;
void bfs(int p, int q)
{
	int st, dr;
	st = dr = 1;
	v[p] = 1;
	x[1] = p;
	t[p] = 0;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1; i <= n ; ++i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = 1;
				x[dr] = i;
				t[i] = k;
			}
		st ++;
	}
}
void reconstituire(int p)
{
	if(p)
	{
		reconstituire(t[p]);
		sol[ ++nsol ] = p;
	}
}
void afis(int *x , int n)
{
	for(int i = 1; i <= n ;++i)
		fout << x[i] << " ";
	fout << endl;
}
int main()
{
    int i , j;
    fin >> n >> p >> q >> r;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
	for(int  i = 1 ; i <= n ; ++i)
		t[i] = 0, v[i] = 0;
    bfs(p , r);
    reconstituire(t[r]);
    for(int  i = 1 ; i <= n ; ++i)
		t[i] = 0, v[i] = 0;
	bfs(r , q);
	reconstituire(q);
	fout << nsol << "\n";
	afis(sol, nsol);
    return 0;
}