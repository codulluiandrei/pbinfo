//Serban Marinel
//O(nxn)
#include <fstream>

using namespace std;

#define MAX 1000000

ifstream fin("munte.in");
ofstream fout("munte.out");

int n, i, j, parcurgere, munti = 0, cati;
int x[110];
bool gasit_munte;

int main()
{
    fin >> n;
    for (i = 1; i <= n; ++i) fin >> x[i];
    parcurgere = 1;
    gasit_munte = true;
    while (gasit_munte)
    {
        gasit_munte = false; cati = 0;
        i = 1;
        while (i<n && x[i]>x[i+1]) i++; //trec peste primii descrescatori
        while (i <= n)
        {
            while (i<n && x[i]<x[i+1]) i++; //urc spre varf
            if (i<n)                        //daca mai am elemente
            {
                munti++; cati++;
                x[i] = MAX;         //asta e un varf - il voi elimina
                gasit_munte = true;
            }
            while (i<n && x[i]>x[i+1]) i++; //cobor muntele
            if (i<n && x[i]>x[i-1])
                i--;
            else
                if (i == n)
                    break;
        }
        if (parcurgere == 1)
        {
            fout << munti << '\n';
            parcurgere++;
        }
        //elimin varfurile
        i = 1;
        while (i < n)
        {
            while (x[i] != MAX && i<n) i++;
            for (j = i; j<n; ++j) x[j] = x[j+1];
        }
        if (gasit_munte) n -= cati;
    }
    fout << munti << '\n';
    fout << n << '\n';
    fout.close();

    return 0;
}
