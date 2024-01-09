#include <iostream>
#include <fstream>
using namespace std;

int n , A[105][105], C[105] , v[105], vT[105], nrC;

int F[105];

void Dfs(int x)
{
	v[x] = 1;
	for(int i = 1 ; i <= n ; i ++)
		if(v[i] == 0 && A[x][i] == 1)
			Dfs(i);
}

void DfsT(int x)
{
	vT[x] = 1;
	for(int i =1 ; i <= n ; i ++)
		if(vT[i] == 0 && A[i][x] == 1)
			DfsT(i);
}

int main()
{
    int i , j , m;
    cin >> n >> m;
    while( m )
    {
    	cin >> i >> j;
    	A[i][j] = 1;
    	m --;
    }
	for(int i = 1 ; i <= n ; ++i)
		if(C[i] == 0)
		{
			for(int j = 1; j <= n ; ++j)
				v[j] = vT[j] = 0;
			nrC ++;
			Dfs(i); DfsT(i);
			for(int j = 1; j <= n ; ++j)
				if(v[j] == 1 && vT[j] == 1)
					C[j] = nrC;
		}
		
	for(int i = 1 ; i <= n ; i ++)
		F[C[i]] ++;
	
	int cnt = 0;
	
	
	
	for(int i = 1 ; i <= nrC ; i ++)
		if(F[i] == 1)
			cnt ++;
			
	cout << cnt << endl;
	
    return 0;
}
