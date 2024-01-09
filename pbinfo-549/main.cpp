#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("epidemie.in");
ofstream fout("epidemie.out");

int n , a[1005][1005];
int x[1005], // coada pentru parcurgerea in latime
	v[1005], // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
    d[1005]; // distantele la varfuri
int st, dr;

int main()
{
    int i , j, m, k , p;
    fin >> n >> m;
    while( m )
    {
        fin >> i >> j;
        a[i][j] = a[j][i] = 1;
        m --;
    }
    fin >> k;
	for( ; k ; --k)
	{
        fin >> p;
        x[++dr] = p;
        v[p] = d[p] = 1;
	}
	st = 1;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1; i <= n ; ++i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = 1;
				x[dr] = i;
				d[i] = d[k] + 1;
			}
		st ++;
	}
	int C = 0;
	for(int i = 1 ; i <= n ; ++i)
		if(d[i] > C)
            C = d[i];
	fout << C;
	return 0;
}
