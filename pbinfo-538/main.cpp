#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lungimeminima.in");
ofstream fout("lungimeminima.out");
int n , p , L , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105], // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
	d[105]; // vectorul de distante
void bfs(int p)
{
	int st, dr;
	st = dr = 1;
	v[p] = 1;
	x[1] = p;
	d[p] = 0;
	while(st <= dr)
	{
		int k = x[st];
		for(int i = n; i >= 1  ; --i)
			if(v[i] == 0 && a[k][i] == 1)
			{
				dr ++;
				v[i] = 1;
				x[dr] = i;
				d[i] = d[k]+1;
			}
		st ++;
	}
}
int main()
{
    int i , j;
    fin >> n >> p >> L;
    while(fin >> i >> j)
    {
    	a[i][j] = a[j][i] = 1;
    }
    bfs(p);
    int cnt = 0;
    for(int i = 1 ; i <= n ; ++i)
		if(d[i] == L)
			cnt ++;
	fout << cnt << "\n";
	for(int i = 1 ; i <= n ; ++i)
		if(d[i] == L)
			fout << i << " ";
    return 0;
}