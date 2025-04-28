#include <fstream>
#define f first
#define s second
const int NMAX=505;
const int QMAX=1005;
using namespace std;
ifstream fin("drar.in");
ofstream fout("drar.out");
bool dp[3][6][NMAX][NMAX];
///dp[k][s][i][j]=true, daca poate ajunge stresu
///in [i, j] prin k pasi <=> k timp (k%2-pt memorie)
///stiind ca ultima data a fost in camera [i+dl[s], j+dc[s]]
///s=4 reprezinta ca s-a ajuns printr-un as
///nu ne intereseaza sa stocam ce as datorita restrictiei
int dl[]= {0, 0, -1, 1, 5};
int dc[]= {-1, 1, 0, 0, 7};
int n, m, q, x, y, nb;
pair<int, int> v[QMAX], vv[QMAX], timp[NMAX];
char t[NMAX];
bool bloc[NMAX][NMAX];
bool inside(int, int);
bool ad(int, int, int, int);
int main()
{
    int prec=0, crt=1;
    int l=1, c=1, lg=0;
    int i, j, k, d, s, a, b;
    fin>>n>>m>>q>>x>>y>>nb;
    for(i=1; i<=nb; i++)
    {
        fin>>a>>b;
        bloc[a][b]=true;
    }
    dp[prec][4][x][y]=true;
    for(i=1; i<=q; i++)
    {
        fin>>v[i].f>>v[i].s;
        fin>>vv[i].f>>vv[i].s;
    }
    fin>>t;
    if(x==1 && y==1) ///timpul minim e 0
    {
        fout<<0<<'\n';
        return 0;
    }
    timp[0]= {1, 1};
    ///nu e necesar sa initializez timp[i][j] cu 1e9
    ///pt ca verific timpul 0 separat
    for(lg=0; t[lg]; lg++)
    {
        if(t[lg]=='R') c++;
        if(t[lg]=='L') c--;
        if(t[lg]=='U') l--;
        if(t[lg]=='D') l++;
        timp[lg+1]= {l, c};
    }
    for(k=1; k<=lg; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(d=0; d<5; d++)
                {
                    dp[crt][d][i][j]=false;
                }
            }
        }
        ///adiacente
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(!bloc[i][j])
                {
                    for(d=0; d<4; d++)
                    {
                        if(inside(i+dl[d], j+dc[d]))
                        {
                            for(s=0; s<5; s++)
                            {
                                ///conditia cu ultima camera
                                ///a=[i, j]
                                ///aa=[i+dl[d], j+dc[d]]
                                ///aaa=[i+dl[d]+dl[s], j+dc[d]+dc[s]]
                                ///aaa -> aa -> a
                                ///dp[crt][d][i][j] -> imi zice ca am venit in [i, j] din [i+dl[d], j+dc[d]]
                                ///dp[prec][s][i+dl[d]][j+dc[d]] -> am venit in [i+dl[d], j+dc[d]] din [i+dl[d]+dl[s], j+dc[d]+dc[s]]
                                ///aaa!=a -> dl[d]+dl[s]!=0 || dc[d]+dc[s]!=0
                                if(dl[d]+dl[s]!=0 || dc[d]+dc[s]!=0)
                                    dp[crt][d][i][j]|=dp[prec][s][i+dl[d]][j+dc[d]];
                            }
                        }
                        if(timp[k].f==i && timp[k].s==j && dp[crt][d][i][j])
                        {
                            ///am gasit solutie in timpul minim k
                            fout<<k<<'\n';
                            return 0;
                        }
                    }
                }
            }
        }
        for(i=1; i<=q; i++) ///asi
        {
            ///daca sunt adiacente dau skip pt ca am verificat inainte
            if(!bloc[vv[i].f][vv[i].s] && !ad(vv[i].f, vv[i].s, v[i].f, v[i].s))
            {
                for(d=0; d<5; d++)
                    dp[crt][4][vv[i].f][vv[i].s]|=dp[prec][d][v[i].f][v[i].s];
                if(timp[k]==vv[i] && dp[crt][4][vv[i].f][vv[i].s])
                {
                    ///am gasit solutie in timpul minim k
                    fout<<k<<'\n';
                    return 0;
                }
            }
        }
        crt=1-crt;
        prec=1-prec;
    }
    fout<<-1<<'\n';
    return 0;
}
bool inside(int lin, int col)
{
    return (lin>=1 && lin<=n && col>=1 && col<=m);
}
bool ad(int l1, int c1, int l2, int c2)
{
    int i;
    for(i=0; i<4; i++)
    {
        if(l1+dl[i]==l2 && c1+dc[i]==c2)
            return true;
    }
    return false;
}