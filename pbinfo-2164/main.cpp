#include <fstream>
#define nmax 701
using namespace std;
int a[nmax][nmax], n, x;
void Citire()
{
    int i, j;
    ifstream fin("munte1.in");
    fin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fin >> a[i][j];
    fin >> x;
    fin.close();
}
/// ret. 0 daca x nu apare pe linia k din matrice
/// ret. j daca x apare pe pozitia a[k,j]
int CautBin(int k, int x)
{
    int st, dr, mid;
    st = 1; dr = n;
    while (st <= dr)
    {
        mid = (st + dr) / 2;
        if (a[k][mid] == x) return mid;
        if (a[k][mid] < x) st = mid + 1;
        else dr = mid - 1;
    }
    return 0;
}
void Rezolva()
{
    int k, j;
    ofstream fout("munte1.out");
    for (k = 1; k <= n; k++)
    {
        j = CautBin(k, x);
        if (j != 0)
        {
            fout << k << " " << j << "\n";
            fout.close();
            return;
        }
    }
}
int main()
{
    Citire();
    Rezolva();
    return 0;
}