// implementare Dan Pracsiu
// Complexitate O(nrcif), unde nrcif este numarul cifrelor lui N 
// 100 puncte
#include <fstream>
#define inFile "tcif.in"
#define outFile "tcif.out"
#define Dim 1003

using namespace std;

int t[Dim]; // in a retin cifrele lui n
int sol[Dim]; // in sol retin numarul solutie
int n; // numarul de cifre ale lui N
int a[3], cif[3];

int AlegeCifra(int x)
{
    if (cif[0] >= x && a[0] > 0)
    {
        //cout << x << "\n";
        return 0;
    }
    if (cif[1] >= x && a[1] > 0) return 1;
    if (cif[2] >= x && a[2] > 0) return 2;
    return -1;
}

int main()
{
    int i, j, k, nr, gata;
    char s[Dim];

    // citire
    ifstream fin(inFile);
    fin >> a[0] >> a[1] >> a[2] >> cif[0] >> cif[1] >> cif[2];
    fin >> s;
    fin.close();

    // init
    for (n = 0; s[n]; ++n)
        t[n] = s[n] - '0';

    for (j = 0; j < 2; ++j)
        for (k = j + 1; k < 3; ++k)
            if (cif[j] > cif[k])
            {
                nr = cif[j];
                cif[j] = cif[k];
                cif[k] = nr;
                nr = a[j];
                a[j] = a[k];
                a[k] = nr;
            }

    // rezolvare caz 1 : n < a + b + c
    if (n < a[0] + a[1] + a[2])
    {
        ofstream fout(outFile);
        if (cif[0] == 0)
        {
            fout << cif[1];
            a[1]--;
        }
        for (i = 0; i < 3; ++i)
            for (j = 1; j <= a[i]; ++j)
                fout << cif[i];
        fout << "\n";
        fout.close();
        return 0;
    }

    // caz 2 : n = a + b + c
    i = 0;
    gata = 0;
    while (!gata && (i < n) && ((k = AlegeCifra(t[i])) != -1))
    {
        sol[i] = k;
        a[k]--;
        if (cif[sol[i]] > t[i]) gata = 1;
        else i++;
    }
    if (gata == 1) // pun restul cifrelor in sol, ordonate crescator
    {
        for (k = 0; k < 3; ++k)
            for (j = 1; j <= a[k]; ++j)
                sol[++i] = k;
    }
    else // ma intorc inapoi
    {
        i--;
        while ((k = AlegeCifra(t[i] + 1)) == -1)
        {
            a[sol[i]]++; // pun cifra inapoi
            i--;
        }
        a[sol[i]]++;
        sol[i] = k;
        a[k]--;
        for (k = 0; k < 3; ++k)
            for (j = 1; j <= a[k]; ++j)
                sol[++i] = k;
    }

    ofstream fout(outFile);
    for (i = 0; i < n; ++i)
        fout << cif[sol[i]];
    fout << "\n";
    fout.close();

    return 0;
}
