/*
    Eugen Nodea
    Implementare - fill pe coada
*/
# include <cstdio>
# include <queue>
# define nmax 1002
# define mmax 1002
using namespace std;
// evident ca se poate renunta la o matrice
int n,m,h,A[nmax][mmax],i,j,M[nmax][mmax],ic,jc,sol,x,y,k;
int dx[] = {0, 1, 0,-1};
int dy[] = {1, 0,-1, 0};
typedef pair<short int, short int> celula;
queue <celula> q;
//Verfific daca un patrat este adiacent cu o zona de apa
inline int vecini(int i, int j)
{
    int k,x,y;
    for (k=0; k<4; ++k)
        {
            x = i + dx[k];
            y = j + dy[k];
            if (A[x][y]==0) return 1;
        }
    return 0;
}
//construim coada cu patrate adiacente cu patrate indundate
void add(int i, int j)
{
    int k,x,y;
    for (k=0; k<4; ++k)
        {
            x = i + dx[k];
            y = j + dy[k];
            if (A[x][y] != A[i][j] && A[x][y] > 0 && A[x][y] < h && M[x][y] == 0)
            {
                q.push(make_pair(x, y));
            }
        }
}
void fill(int i, int j)
{
    int k,x,y;
    M[i][j] = h - A[i][j];
    ++sol;
    add(i,j);
    for (k=0; k<4; ++k)
        {
            x = i + dx[k];
            y = j + dy[k];
            if (A[i][j] == A[x][y] && M[x][y] == 0) fill(x,y);
        }
}
int main(){
    freopen("tsunami.in", "r", stdin);
    freopen("tsunami.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &h);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            scanf ("%d ",&A[i][j]);
    //bordez matricea
    for (i=0; i<=n+1; ++i)
    {
        A[i][0] = A[i][m+1] = -1;
    }
    for (i=0; i<=m+1; ++i)
    {
        A[0][i] = A[n+1][i] = -1;
    }
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (A[i][j] < h && M[i][j] == 0 && A[i][j] > 0)
                if (vecini(i,j)) fill(i,j);
	while (!q.empty())
	{
		ic = q.front().first; jc = q.front().second;
		if (M[ic][jc] == 0) fill(ic,jc);
		q.pop();
	}
    printf("%d\n", sol);
	return 0;
}