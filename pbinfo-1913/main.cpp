#include <fstream>
using namespace std;
ifstream cin("mr.in");
ofstream cout("mr.out");
int cost, minim[105][105], linii, coloane, j, i, matrice[105][105], teleportere, coada_i[10000], coada_j[10000], in, sf, iul, jul;
int pereche[1005][1005], cat;
int dir_i[] = {0, -1, 0, 1, 0};
int dir_j[] = {0, 0, 1, 0, -1};
struct copac
{
    int li, ci, ls, cs;
}teleporter[1005];
int main()
{
    cin >> linii >> coloane;
    for(i=1; i <= linii; i++)
    {
        for(j=1; j <= coloane; j++)
        {
            cin >> matrice[i][j];
            if(matrice[i][j] == 0)
            matrice[i][j] = 1;
        }
    }
    for(i=0; i <= linii+1; i++)
    {
        matrice[i][0] = -1;
        matrice[i][coloane+1] = -1;
    }
    for(i=0; i <= coloane+1; i++)
    {
        matrice[0][i] = -1;
        matrice[linii+1][i] = -1;
    }
    cin >> teleportere;
    for(i=1; i <= teleportere; i++)
    {
        cin >> teleporter[i].li >> teleporter[i].ci >> teleporter[i].ls >> teleporter[i].cs;
        pereche[teleporter[i].li][teleporter[i].ci] = i;
        pereche[teleporter[i].ls][teleporter[i].cs] = i;
    }
    coada_i[1] = 1;
    coada_j[1] = 1;
    minim[1][1] = matrice[1][1];
    in = 1;
    sf = 1;
    while(in <= sf)
    {
        for(j=1; j <= 4; j++)
        {
            iul = coada_i[in] + dir_i[j];
            jul = coada_j[in] + dir_j[j];
            if(matrice[iul][jul] != -1)
            {
                cost = minim[coada_i[in]][coada_j[in]] + matrice[iul][jul];
                if(minim[iul][jul] == 0 || minim[iul][jul] > cost)
                {
                    minim[iul][jul] = cost;
                    sf++;
                    coada_i[sf] = iul;
                    coada_j[sf] = jul;
                }
            }
        }
        cat = pereche[coada_i[in]][coada_j[in]];
        if(cat != 0)
        {
            if(coada_i[in] != teleporter[cat].li || coada_j[in] != teleporter[cat].ci)
            {
                iul = teleporter[cat].li;
                jul = teleporter[cat].ci;
            }
            else
            {
                iul = teleporter[cat].ls;
                jul = teleporter[cat].cs;
            }
            cost = minim[coada_i[in]][coada_j[in]] + 1;
            if(cost <= minim[iul][jul] || minim[iul][jul] == 0)
            {
                minim[iul][jul] = cost;
                sf++;
                coada_i[sf] = iul;
                coada_j[sf] = jul;
            }
        }
        in++;
    }
    /*for(i=1; i <= linii; i++)
    {
        for(j=1; j <= coloane; j++)
        {
            cout << minim[i][j]-1 << ' ';
        }
        cout << '\n';
    }*/
    cout << minim[linii][coloane]-1;
}