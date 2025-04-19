#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("conex.in");
ofstream fout("conex.out");
int n , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105]; // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
int conex()
{
	int st, dr;
	st = dr = 1;
	v[1] = 1;
	x[1] = 1;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = 1; i <= n ; ++i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = 1;
				x[dr] = i;
			}
		st ++;
	}
	for(int i = 1 ; i <= n ; ++i)
		if(v[i] == 0)
			return 0;
	return 1;
}
int main()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
    if(conex())
		fout <<"DA";
	else
		fout << "NU";
    return 0;
}