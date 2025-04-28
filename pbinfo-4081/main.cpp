///autori Ivan Andrei & Hangu Calin
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
ifstream in ("alpinistii.in");
ofstream out ("alpinistii.out");
const int max_size = 2e2 + 1, max_dir = 4;
/// 2e2 = 2 * 10 ^ 2
int a[max_size][max_size], dr[max_size], st[max_size], h[max_size], n, m, c, total, rez,
di[] = {-1, 0, 1, 0},
dj[] = {0, 1, 0, -1};
queue <pair <int,int> > coada;
stack <int> stiva;
void umplere (int is, int js)
{
    /// nu este neaparata nevoie de implementarea algoritmului de fill adaptat din Lee
    total++;
    a[is][js] = 1;
    coada.push(make_pair(is, js));
    while (!coada.empty())
    {
        int i = coada.front().first, j = coada.front().second;
        for (int k = 0; k < max_dir; k++)
        {
            int iv = i + di[k], jv = j + dj[k];
            if (iv > 0 && jv > 0 && iv <= n && jv <= m && a[iv][jv] == 0)
            {
                a[iv][jv] = 1;
                total++;
                coada.push(make_pair(iv, jv));
            }
        }
        coada.pop();
    }
}
void calc_st ()
{
    /// ne asiguram ca stiva este vida
    while (!stiva.empty())
    {
        stiva.pop();
    }
    for (int j = 1; j <= m; j++)
    {
        ///cat timp avem elemente in varful stivei care sunt mai mari decat elementul curent le eliminam pana cand stiva devine vida sau varful stivei este mai mic decat elementul curent
        while (!stiva.empty() && h[stiva.top()] >= h[j])
        {
            stiva.pop();
        }
        ///daca stiva este vida ==> elementul curent este minim pe tot vectorul din partea stanga
        if (stiva.empty())
        {
            st[j] = 0;
        }
        ///in caz contrar limita din stanga a secventei pe care elemntul curent este minim va deveni varful stivei
        else
        {
            st[j] = stiva.top();
        }
        ///adaugam indicele
        stiva.push(j);
    }
}
void calc_dr ()
{
    while (!stiva.empty())
    {
        stiva.pop();
    }
    /// ne asiguram ca stiva este vida
    for (int j = m; j > 0; j--)
    {
        ///cat timp avem elemente in varful stivei care sunt mai mari decat elementul curent le eliminam pana cand stiva devine vida sau varful stivei este mai mic decat elementul curent
        while (!stiva.empty() && h[stiva.top()] >= h[j])
        {
            stiva.pop();
        }
        ///daca stiva este vida ==> elementul curent este minim pe tot vectorul din partea dreapta
        if (stiva.empty())
        {
            dr[j] = m + 1;
        }
        ///in caz contrar limita din dreapta a secventei pe care elemntul curent este minim va deveni varful stivei
        else
        {
            dr[j] = stiva.top();
        }
        ///adaugam indicele
        stiva.push(j);
    }
}
void citire ()
{
    in >> c >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            in >> a[i][j];
        }
    }
}
void cerinta1 ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            /// facem fill pentru fiecare 0 pe care il gasim
            /// in matrice si det. aria zonei care contine acel 0
            if (a[i][j] == 0)
            {
                umplere(i, j);
                rez = max(rez, total);
                total = 0;
            }
        }
    }
}
void cerinta2 ()
{
    for (int i = 1; i <= n; i++)
    {
        /// calculam cate celule consecutive sunt cu valori
        /// de 0 deasupra elementului pe care il verificam, incepand cu elementul curent
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                h[j] = 0;
            }
            else
            {
                h[j]++;
            }
        }
        /// algoritm de tip ”Skyline”
        /// calculam capetele secventei de lungime maxima
        /// in care h[j] este minim
        /// lungimea secventei va reprezenta cea de - a doua
        /// latura a dreptunghiului nostru
        calc_st();
        calc_dr();
        for (int j = 1; j <= m; j++)
        {
            rez = max(rez, h[j] * (dr[j] - st[j] - 1));
        }
    }
}
void afisare ()
{
    out << rez;
}
int main ()
{
    citire();
    if (c == 1)
    {
        cerinta1();
    }
    else
    {
        cerinta2();
    }
    afisare();
    in.close();
    out.close();
    return 0;
}