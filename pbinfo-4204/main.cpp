#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("estearbore.in");
ofstream fout("estearbore.out");
const int nm=102;
int  n, m, i, j, ok=1;
char a[nm][nm], v[nm] ;
int pa(int x)
{
    int i;
    v[x]=1;
    for(i=1; i<=n; i++)
        if(a[x][i]==1 and v[i]==0)pa(i);
}
int main()
{
    fin >> n;
    while(fin >> i >> j)
    {
        if(a[i][j]==0)m++;
        a[i][j] = a[j][i] = 1;
    }
    if(n!=m+1)fout<<"NU";
        else
        {
            pa(1);
            for(i=2; i<=n; i++)
                if(v[i]==0)ok=0;
            if(ok)fout << "DA";
                else fout << "NU";
        }
    return 0;
}