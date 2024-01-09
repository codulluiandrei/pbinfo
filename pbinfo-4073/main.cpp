#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("componenteconexe5.in");
ofstream fout("componenteconexe5.out");

int n , m , A[1001][1001], Dim[1001], CC[1001], nrc, nrv;

void DFS(int x , int nrc)
{
	CC[x] = nrc;
	Dim[nrc] ++;
	for(int i = 1 ; i <= n ; i ++)
		if(A[x][i] == 1 && CC[i] == 0)
			DFS(i , nrc);
}

int main()
{
    int i , j;
    fin >> n >> m;
    while(m)
    {
		fin >> i >> j;
        A[i][j] = A[j][i] = 1;
        m --;
    }
    nrc = 0;
    for(int i = 1 ; i <= n ; i ++)
		if(CC[i] == 0)
		{
			nrc ++;
			DFS(i , nrc);
			
		}
    int q , x;
    fin >> q;
    while(q)
    {
		fin >> x;
		fout << Dim[CC[x]] << '\n';
		q --;
	}
    return 0;
}
