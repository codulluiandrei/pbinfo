#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("componenteconexe.in");
ofstream fout("componenteconexe.out");

int n , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105]; // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat


void bf(int varf, int nrc)
{
	int st, dr;
	st = dr = 1;
	v[varf] = nrc;
	x[1] = varf;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1; i <= n ; ++i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = nrc;
				x[dr] = i;
			}
		st ++;
	}
}

int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }

    int nrc = 0;
    for(int i=1; i <= n ;++i)
		if(v[i] == 0 )
		{
			nrc ++;
			bf(i , nrc);
		}
	fout << nrc << endl;
	for(int i=1 ; i<= nrc ; ++i)
	{
		for(int j = 1; j<= n ;++j)
			if(v[j] == i)
				fout << j << " ";
		fout << endl;
	}
    return 0;
}
