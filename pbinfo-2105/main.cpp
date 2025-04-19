#include <fstream>
using namespace std;
ifstream fin("moretime.in");
ofstream fout("moretime.out");
long n, m, cp, p, cont[10001], fond[10001];
int r[10001];
int main()
{
    //citirea si construirea vectorilor cu conturi si fonduri ale clientilor premium
    long x, a, y, i, rest, s;
    int u;
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>x>>y;
        a=x;
        u=a%10;
        while (a>9) a/=10;
        if (a==u)    cont[++cp]=x, fond[cp]=y;
    }
    fout<<cp<<'\n';
    //determinarea submultimii de clienti premium pentru care suma fondurilor este divizibila cu cp
    //algoritmul bazat pe principiul cutiei lui Dirichlet
    s=0;
    for (i=1; i<=cp; i++)
    {
        s=s+fond[i];
        if (s%cp==0)
        {
            x=1; y=i;
            break;
        }
        else
        {
            rest=s%cp;
            if (r[rest]==0) r[rest]=i;
            else {
                    x=r[rest]+1;
                    y=i;
                    break;
                 }
        }
    }
    //afisarea conturilor clientilor selectati
    fout<<y-x+1<<'\n';
    for (int i=x; i<=y; i++)
        fout<<cont[i]<<' ';
    fout.close();
    return 0;
}