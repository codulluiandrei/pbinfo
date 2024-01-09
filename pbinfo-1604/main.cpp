#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

int n , a[105][105];
int x[105], // coada pentru parcurgerea in latime
	v[105]; // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat
int d[105]; // distanța minimă de la rădăcină la vârfurile grafului
	

void bfs(int varf)
{
    for(int i = 1 ; i <= n ; i ++)
        d[i] = v[i] = x[i] = 0;
	int st, dr;
	st = dr = 1;
	v[varf] = 1;
	x[1] = varf;
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
}

int main()
{
    int i , j , m , k , x , y;
    fin >> n >> m;
    while(m > 0)
    {
        fin >> i >> j;
    	a[i][j] = a[j][i] = 1;
        m --;
    }
	fin >> k;
    while(k)
    {
        fin >> x >> y;
        bfs(x);
        fout << d[y] << endl;;
        k --;
    }
	return 0;
}
