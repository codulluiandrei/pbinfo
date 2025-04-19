#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lantminim.in");
ofstream fout("lantminim.out");
int n , p , q , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105], // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
	t[105], // vectorul de tati
	d[105]; // vectorul de tati
void bfs(int p, int q)
{
	int st, dr;
	st = dr = 1;
	v[p] = 1;
	x[1] = p;
	t[p] = 0;
	d[p] = 1;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1; i <= n ; ++i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = 1;
				x[dr] = i;
				d[i] = d[k]+1;
				t[i] = k;
			}
		st ++;
	}
}
void afis_lant(int p)
{
	if(p)
	{
		afis_lant(t[p]);
		fout << p << " ";
	}
}
void afis(int *x , int n)
{
	for(int i = 1; i <= n ;++i)
		cout << x[i] << " ";
	cout << endl;
}
int main()
{
    int i , j;
    fin >> n >> p >> q;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
    bfs(p,q);
    //afis(t,n);
	fout << d[q] << endl;;
	afis_lant(q);
    return 0;
}