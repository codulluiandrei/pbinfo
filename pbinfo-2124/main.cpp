//Marinel Serban ianuarie 2015
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
ifstream fin ("ornament.in");
ofstream fout("ornament.out");
long k, l, m, n;
long a[18][18], b[18][18];
int luate[20], CeFac;
long long sol = 0;
void scrie()
{
    int i, j;
    for (i = 1; i <= k; i++)
        {
            for (j = 1; j <= k; j++)
                fout << a[i][j] << ' ';
            fout << '\n';
        }
    //fout << '\n';
    fout.close();
}
void back(long l, long c)
{
    long p;
    if (l == k + 1)  //am umplut k linii
        {
          if (CeFac == 1)
            {
               scrie();
               exit(0);
            }
          sol++;
        }
    else
        for (p = 1; p <= n; ++p)     //parcurg cele n patratele
            if (!luate[p])           //daca nu l-am luat inca
                if (l == 1  || b[p][1] == b[a[l-1][c]][3])
                    if (c == 1 || b[p][4] == b[a[l][c-1]][2])
                        {   //se potriveste
                            luate[p] = 1;   //l-am luat
                            a[l][c] = p;    //il pun la locul lui
                            if (c == k)     //daca am umplut linia
                                back(l+1, 1);  //trec la linie noua
                            else            //altfel
                                back(l, c+1);  //trec in aceiasi linie mai departe
                            a[l][c] = 0;    //iau patratelul
                            luate[p] = 0;   //
                        }
}
void Rezolva()
{
    back(1, 1);    //plec de la prima pozitie
}
void ReadData()
{
    int i;
    fin >> n;
    k = sqrt(n);   //atata e k
    for (i = 1; i <= n; i++)
        fin >> b[i][1] >> b[i][2] >> b[i][3] >> b[i][4];
    fin >> CeFac;
    Rezolva();
    if (sol == 0)
        fout << -1 << '\n'; //nu e cazul dar...
    else
        fout << sol << '\n';
    fout.close();
}
int main()
{
    ReadData();
    return 0;
}