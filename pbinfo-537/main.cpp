#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("componenteconexe2.in");
ofstream fout("componenteconexe2.out");
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
	//determinam cate muchii are fiecare componenta conexa
	for(int i = 1; i < n ; i++)
		for(int j = i + 1 ; j <= n ; ++j)
			if(a[i][j] == 1)
				nrm[v[i]] ++;
	// determinam rezultatul: din fiecare componenta putem elimina atatea muchii incat sa ramana arbore
	int C = 0;
	for(int i = 1 ; i <= nrc ; ++i)
		C += nrm[i] - nrv[i] + 1;
	fout << C;
	return 0;
}