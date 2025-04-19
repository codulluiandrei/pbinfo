// Prof.Anca Uriciuc
#include <fstream>
using namespace std;
ifstream fin("meteo.in");
ofstream fout("meteo.out");
int nrmax, k, i, t, a[1001], n;
int main()
{
    fin >> n;
    nrmax = 0;
    k = 1;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 2; i <= n; i++) {
        if ((a[i] >= 0 && a[i-1] < 0) || (a[i-1] >= 0 && a[i] < 0))
            k++;
        else {
            if (k >= nrmax) {
                nrmax = k;
                t = i-1;
            }
            k = 1;
        }
    }
    if (k >= nrmax) {
        nrmax = k;
        t = i-1;
    }
    if ( nrmax == 1)
    fout << 0 << '\n';
    else {
    fout << nrmax << '\n';
    for (i = t+1-nrmax; i <= t; i++)
        fout << a[i] <<" ";
    fout << '\n';
    }
    return 0;
}