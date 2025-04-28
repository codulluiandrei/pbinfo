#include<fstream>
#include<vector>
using namespace std;
vector<int> L[7501];
int n, d[7501], viz[7501], x, y;
int dx[7501], dy[7501], a[7501], nod[7501], b[7501];
void Citire()
{
    int i, m, ii, jj;
    ifstream f("graf1.in");
    f >> n >> m >> x >> y;
    for (i = 1; i <= m; i++)
    {
        f >> ii >> jj;
        L[ii].push_back(jj);
        L[jj].push_back(ii);
    }
    f.close();
}
void BFS(int x, int *dx)
{
    int pr, ul, coada[7501], k, j ;
    unsigned int i ;
    for (j=1 ; j<=n ; j++) viz[j] = 0 ;
    pr = ul = 0 ;
    coada[0] = x ;
    dx[x] = 0 ;
    viz[x] = 1 ;
    while (pr <= ul)
    {
        k = coada[pr++] ;
        for (i=0 ; i<L[k].size() ; i++)
        {
            j = L[k][i] ;
            if (!viz[j])
            {
                viz[j] = 1 ;
                coada[++ul] = j ;
                dx[j] = 1 + dx[k] ;
            }
        }
    }
}
void Afisare()
{
    int i, minim ;
    minim = dx[y] ;
    for (i=1 ; i<=n ; i++)
        if (minim != dx[i] + dy[i])
            dx[i] = -1 ;
    for (i=1 ; i<=n ; i++)
        if (dx[i] != -1)
        {
            a[dx[i]]++ ;
            nod[dx[i]] = i ;
        }
    for (i=0 ; i<=n ; i++)
        if (a[i] == 1)
            b[nod[i]] = 1 ;
    int kk = 0 ;
    for (i=1 ; i<=n ; i++)
        if (b[i] == 1) kk++ ;
    ofstream fout("graf1.out") ;
    fout<<kk<<"\n" ;
    for (i=1 ; i<=n ; i++)
        if (b[i] == 1) fout<<i<<" " ;
    fout<<"\n" ;
    fout.close() ;
}
int main()
{
    Citire();
    BFS(x,dx);
    BFS(y,dy);
    Afisare();
    return 0;
}