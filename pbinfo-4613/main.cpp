// Mihaela Cismaru
#include<fstream>
#include<vector>
using namespace std;
ifstream in ("nestemate.in");
ofstream out ("nestemate.out");
int nestemate[100005][4],coada[100005],cost[100005];
bool frecventa[500005];
vector<int> urmator[500005];
int T,N,start,final,nod,nod_urm,valoare,maxim;
int main (void) {
    in >> T;
    for (int us = 1; us <= T; us ++) {
        in >> N >> start >> final;
        maxim = 0;
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= 3; j ++) {
                in >> nestemate[i][j];
                maxim = max (maxim, nestemate[i][j]);
                urmator[nestemate[i][j]].push_back (i);
            }
        }
        coada[1] = start;
        cost[start] = 1;
        for (int st = 1, dr = 1; st <= dr; st ++) {
            nod = coada[st];
            for (int aux = 1; aux <= 3; aux ++) {
                valoare = nestemate[nod][aux];
                if (frecventa[valoare] == false) {
                    frecventa[valoare] = true;
                    for (int j = 0; j < urmator[valoare].size(); j ++) {
                        nod_urm = urmator[valoare][j];
                        if (cost[nod_urm] == 0) {
                            coada[++dr] = nod_urm;
                            cost[nod_urm] = cost[nod] + 1;
                        }
                    }
                }
            }
        }
        out <<cost[final]-1 <<"\n";
        for (int i = 1; i <= maxim; i ++) {
            urmator[i].clear();
            frecventa[i] = false;
        }
        for (int i = 1; i <= N; i ++) {
            cost[i] = 0;
        }
    }
    return 0;
}