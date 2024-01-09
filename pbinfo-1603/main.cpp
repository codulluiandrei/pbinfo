#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("componenteconexe3.in");
ofstream fout("componenteconexe3.out");

int n , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105]; // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
int nrv[105], // numarul de varfuri din fiecare componenta conexa
	nrm[105]; // numarul de muchii din fiecare componenta conexa

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
	//determinam componentele conexe
    int nrc = 0;
    for(int i=1; i <= n ;++i)
		if(v[i] == 0 )
		{
			nrc ++;
			bf(i , nrc);
		}
	//determinam cate varfuri are fiecare componenta conexa
	for(int i = 1; i <= n ; i++)
		nrv[v[i]] ++;
	//determinam indexul componentei cu numar maxim de varfuri
    int CC = 1;
    for(int i = 2 ; i <= nrc ; i ++)
        if(nrv[i] > nrv[CC])
            CC = i;
    //determinareprezentanul componentei CC
    int repr = 0;
    for(int i = 1 ; i <= n && repr == 0; i ++)
        if(v[i] == CC)
            repr = i;
    fout << repr << " " << nrv[CC];
	return 0;
}
