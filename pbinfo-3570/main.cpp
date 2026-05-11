#include<stdio.h>
#include<string.h>
#define maxn 512
int N, M, V[ maxn ][ maxn ], nr[ maxn];
int simetric( int x, int y, int l)
{
	for( int i = x; i <= x + l - 1; i++)
		for( int j = y ; j <= y + l - 1; j++)
			if( V[i][j] != V[ x + j - y ][ y + i - x ] )
				return 0;
	return 1;
}
int main()
{
	freopen("simetric.in","r",stdin);
	freopen("simetric.out","w",stdout);
	memset( nr, 0, sizeof( nr ));
	scanf("%d %d", &N, &M);
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= M; ++j)
			scanf("%d", &V[ i ][ j ]); 
	int optim = 1;
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= M; ++j)
			for( int l = 1; l + i - 1 <= N && l + j - 1 <= M; ++l)
				if( simetric( i, j, l) )
					{nr[ l ]++; if( l > optim) optim = l;}
				else break;
	for( int i = 1; i <= optim; i++)
		printf("%d\n", nr[i]); 
	return 0;
}