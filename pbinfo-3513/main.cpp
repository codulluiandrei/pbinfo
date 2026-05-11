#include <bits/stdc++.h>
using namespace std;
ifstream f("covoare1.in");
ofstream g("covoare1.out");
int n, m, p;
int lin = 1, col = 1;     //coordonatele coltului din stanga sus ale urmatorului dreptunghi
vector<pair<int, int>> v; //aici vom actualiza pentru fiecare coloana pana la ce linie a fost "completata"
                          //si cate coloane trebuie sa "sarim" de acolo daca ajungem la ea
void get_next(int &, int &);
int check(int &, int &);
int main()
{
    ios_base::sync_with_stdio(false);
    g.tie(nullptr);
    f.tie(nullptr);
    f >> n >> m >> p;
    v.resize(m + 1);
    for (int i = 1, x, y; i <= p; i++)
    {
        g << lin << " " << col << '\n';
        f >> x >> y;
        get_next(x, y); //obtinem in lin si col coordonatele noului dreptunghi
    }
    return 0;
}
void get_next(int &dx, int &dy) // latimea si lungimea noului dreptunghi
{
    v[col] = {lin + dx - 1, dy}; //noua linie si cat trebuie sa "sarim"
    while (true) //cat timp nu am gasit o pozitie libera
    {
        int aux = check(lin, col); //aceasta functie nu va returna 0 niciodata cand este apelata prima data
                                   //pentru ca o vom apela cu coordonatele coltului din stanga ale dreptunghiului pe care tocmai l-am adaugat
        if (!aux) //daca nu este ocupata celula spre care ne "redirectioneaza" dreptunghiul actual ne oprim
            return;
        col += aux; //celula fiind ocupata, ne deplasam in continuare in functie de cat ne indica coloana
        if (col == m + 1)
            col = 1, lin++;
    }
}
int check(int &x, int &y) //returnam cate elemente trebuie sa mergem la dreapta daca e ocupata pozitia sau 0 daca e libera
{
    if (x <= v[y].first)
        return v[y].second;
    return 0;
}