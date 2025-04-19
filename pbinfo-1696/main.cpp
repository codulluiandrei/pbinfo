#include <fstream>
#define inFile "perechi2.in"
#define outFile "perechi2.out"
#define Dim 10005
using namespace std;
int a[Dim];
int P[Dim];
int n;
void Cerinta1()
{
    int i, cnt;
    ofstream fout(outFile);
    /// verifica nr de numere diferite
    cnt = 1;
    for (i = 2; i <= n; ++i)
        if (a[i] != a[i - 1]) cnt++;
    if (cnt != 2 || a[2] == a[3])
    {
        fout << "0\n";
        fout.close();
        return ;
    }
    cnt = a[3] - a[2];
    fout<<P[1]<<" "<<P[2]<<" "<<cnt<<"\n";
    fout.close();
}
void Cerinta2()
{
    int i, ultim, v;
    ofstream fout(outFile);
    ultim = n;
    for (i = 1; i < n; i += 2)
    {
        v = a[ultim] - a[i];
        if (v > 0)
        {
            a[i] += v;
            a[i + 1] += v;
            fout << P[i] << " " << P[i + 1] << " " << v << "\n";
            a[++ultim] = a[i];
            P[ultim] = P[i];
            a[++ultim] = a[i + 1];
            P[ultim] = P[i + 1];
        }
    }
    for ( ; i < ultim; i += 2)
    {
        v = a[ultim] - a[i];
        if (v > 0)
        {
            a[i] += v;
            a[i + 1] += v;
            fout << P[i] << " " << P[i + 1] << " " << v << "\n";
        }
    }
    fout.close();
}
int main()
{
    int i, j, C;
    int aux;
    //citire
    ifstream fin(inFile);
    fin >> C;
    fin >> n;
    for (i = 1; i <= n; ++i)
    {
        fin >> a[i];
        P[i] = i;
    }
    fin.close();
    //sortare
    for (i = 1; i < n; ++i)
        for (j = i + 1; j <= n; ++j)
            if (a[i] > a[j])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                aux = P[i];
                P[i] = P[j];
                P[j] = aux;
            }
    if (C == 1) Cerinta1();
    else Cerinta2();
    return 0;
}