#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("traseu2.in");
ofstream fout("traseu2.out");
int a[102][102], n, L, C, LF, CF;
char s[251];
void read();
void deplasare();
int main()
{
    read();
    deplasare();
    fout<<LF<<' '<<CF;
    fin.close();
    fout.close();
    return 0;
}
void read()
{
    int i, j;
    fin>>n>>L>>C;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            fin>>a[i][j];
    fin>>s;
}
void deplasare()
{
    int xn=0, yn=0, x, y, m, i;
    m=strlen(s);
    x=L; y=C;
    for (i=0; i<m; i++)
    {
        switch (s[i])
        {
            case 'N': xn=x-1, yn=y; break;
            case 'E': xn=x, yn=y+1; break;
            case 'S': xn=x+1, yn=y; break;
            case 'V': xn=x, yn=y-1; break;
        }
        if (xn==0 || xn==n+1 || yn==0 || yn==n+1) break;
        if (a[xn][yn]==0) x=xn, y=yn;
    }
    LF=x; CF=y;
}