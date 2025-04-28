# include <fstream>
# include <queue>
# define NMax 1003
using namespace std;
ifstream f("sahara.in");
ofstream g("sahara.out");
short dx[]={-1, 0, 1, 0};
short dy[]={ 0, 1, 0,-1};
struct cel
{
    short l, c;
};
queue <cel> q;
int U[NMax][NMax];
int a[NMax][NMax];
int N, M, Q, nr, Max;
void fill(short l, short c)
{
    cel x, y;
    short k;
    U[l][c] = 0;
    x.l = l, x.c = c;
    q.push(x);
    while( !q.empty() )
    {
        x = q.front(); q.pop();
        for(k=0; k<4; ++k)
        {
            l = x.l + dx[k];
            c = x.c + dy[k];
            if (U[l][c] >= Q)
                {
                    U[l][c] = 0;
                    y.l = l; y.c = c;
                    q.push(y);
                    ++nr;
                }
        }
    }
}
int main()
{
    short i, j, x1, x2, y1, y2, q;
    int T, aux;
    f >> N >> M >> Q;
    f >> T;
    while ( T-- )
    {
        f >> x1 >> y1 >> x2 >> y2 >> q;
        // smenul lui Mars
        a[x1][y1] += q;
        a[x1][y2 + 1] -= q;
        a[x2 + 1][y1] -= q;
        a[x2 + 1][y2 + 1] += q;
    }
    //procesam matricea
    for (i=1; i<=N; ++i)
    {
        aux = 0;
        for (j=1; j<=M; ++j)
        {
            a[i][j] += a[i-1][j];
                aux += a[i][j];
            U[i][j]  = aux;
        }
    }
    for (i=1; i<=N; ++i)
        for(j=1; j<=M; ++j)
            if (U[i][j] >= Q)
                {
                    nr = 1;
                    fill(i, j);
                    if (nr > Max) Max = nr;
                }
    g << Max << "\n";
    return 0;
}