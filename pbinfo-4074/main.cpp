#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("distante.in");
ofstream fout("distante.out");
int n , m , A[1001][1001], V[1001], Dp[1001], Dq[1001], p , q;
void BFS(int x , int D[])
{
	for(int i = 1 ; i <= n ; i ++)
		V[i] = 0;
	int Q[1001], st = 1 , dr = 0;
	Q[++dr] = x, V[x]  = 1, D[x] = 0;
	while(st <= dr)
	{
		int k = Q[st];
		for(int i = 1 ; i <= n ; i ++)
			if(A[k][i] == 1 && V[i] == 0)
			{
				Q[++ dr] = i;
				V[i] = 1;
				D[i] = D[k] + 1;
			}
		st ++;
	}
}
int main()
{
    int i , j;
    fin >> n >> m >> p >> q;
    while(m)
    {
		fin >> i >> j;
        A[i][j] = A[j][i] = 1;
        m --;
    }
    BFS(p, Dp);
    BFS(q, Dq);
    for(int i = 1 ; i <= n ; i ++)
		if(Dp[i] == Dq[i])
			fout << i << " ";
	fout << '\n';
    return 0;
}