//problema mese
/*
 *  Pentru a afla numarul de mese, parcurgem matricea si numaram elementele 
 *  care nu au vecini in sus si in stanga (coltul stanga sus al unei mese)
 * 
 *  Pentru a afla ariile determinam dimensiunile, si facem produsul
 * 
 * */
#include <iostream>
using namespace std;
int a[105][105], n, m;
int main(){
	cin  >> n >> m;
	for (int i = 1 ;i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cin >> a[i][j];
	//bordam matricea cu 1 - util pentru a nu avea cazuri particulare pe prima sau ultima coloana, prima sau ultima linie
	for(int i = 0 ; i <= n + 1 ; i ++)
		a[i][0] = a[i][m + 1] = 1;
	for(int j = 0 ; j <= m + 1; j ++)
		a[0][j] = a[n+1][j] = 1;
	int cnt = 0, gata = 0;
	while(!gata)
	{
		int gasit_uscat = 0, se_erodeaza = 0;
		for(int i =1 ; i <= n ; ++i)
			for(int j = 1 ; j <= m ; ++j)
				if(a[i][j] == 1)
				{
					gasit_uscat = 1;
					int nrv = 0;
					if(a[i][j-1] == 0)
						nrv ++;
					if(a[i][j+1] == 0)
						nrv ++;
					if(a[i+1][j] == 0)
						nrv ++;
					if(a[i-1][j] == 0)
						nrv ++;
					if(nrv > 1)
					{
						se_erodeaza = 1;
						a[i][j] = 2;
					}
				}
		if(!gasit_uscat)
			gata = 1;
		else
			if(!se_erodeaza)
			{
				cnt = -1;
				gata = 1;
			}
			else
			{
				cnt ++;
				for(int i =1 ; i <= n ; ++i)
					for(int j = 1 ; j <= m ; ++j)
						if(a[i][j] == 2)
							a[i][j] = 0;
			}
	}
	cout << cnt << endl;
	return 0;
}