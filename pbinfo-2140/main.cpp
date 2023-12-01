#include <fstream>

using namespace std;

struct pereche
{
    short x, y;
};

pereche a[251][251];

int NrPasi(short p, short q, short cnt)
{
    if (a[p][q].x == p && a[p][q].y == q) return 0;
    short i, j;
    int nrp = 0;
    i = p; j = q;
    while (true)
    {
        nrp++;
        p = a[i][j].x;
        q = a[i][j].y;
        a[i][j].x = a[i][j].y = cnt;
        i = p; j = q;
        if (a[i][j].x == 0) return nrp;
        if (a[i][j].x == cnt) return nrp + 1;
        if (a[i][j].x < 0) return nrp;
    }
    return 1;
}

int main()
{
    int nrTotal;
    short xs, ys, i, j, P, cnt;
    pereche w;

    /// citire
    ifstream fin("poartas.in");
    fin >> P;
    for (i = 1; i <= P; i++)
    {
        fin >> xs >> ys >> w.x >> w.y;
        a[xs][ys] = w;
    }
    fin.close();

    /// calcul
    nrTotal = cnt = 0;
    for (i = 1; i <= 250; i++)
        for (j = 1; j <= 250; j++)
            if (a[i][j].x > 0)
            {
                cnt--;
                nrTotal += NrPasi(i, j, cnt);
            }

    /// afisare
    ofstream fout("poartas.out");
    fout << nrTotal << "\n";
    fout.close();

    return 0;
}
