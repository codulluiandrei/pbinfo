#include <bits/stdc++.h>
using namespace std;
ifstream fin("gradina1.in");
ofstream fout("gradina1.out");
const int dl[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
int n,m,s,a[60][60],b[60][60],u[101], amax, ac, k;
void Read()
{
    int i, j;
    fin >> n >> m >> s;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            fin >> a[i][j];
    for (i = 1; i <= s; i++)
        fin >> u[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            fin >> b[i][j];
    fin.close();
}
void Bordare()
{
    int i;
    for (i = 0; i <= m + 1; i++)
        a[0][i] = a[n + 1][i] = 200;
    for (i = 1; i <= n; i++)
        a[i][0] = a[i][m + 1] = 200;
}
void Fill(int l, int c)
{
    int i;
    for (i = 0; i < 4; i++)
        if (a[l+dl[i]][c+dc[i]]==k)
        {
            ac++;
            a[l+dl[i]][c+dc[i]]=200;
            Fill (l+dl[i],c+dc[i]);
        }
        else if (a[l+dl[i]][c+dc[i]]!=-k && a[l+dl[i]][c+dc[i]]<=0
                 && b[l+dl[i]][c+dc[i]]>=u[k])
        {
            ac++;
            a[l+dl[i]][c+dc[i]]=-k;
            Fill(l+dl[i],c+dc[i]);
        }
}
int main ()
{
    Read();
    Bordare();
    int l, c;
    for (l = 1; l <= n; l++)
        for (c = 1; c <= m; c++)
            if (a[l][c] >= 1 && a[l][c] <= s)
            {
                ac = 1;
                k = a[l][c];
                a[l][c] = 200;
                Fill(l, c);
                if (ac > amax) amax = ac;
            }
    fout << amax << "\n";
    fout.close();
    return 0;
}