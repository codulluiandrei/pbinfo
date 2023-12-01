#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("grupuri.in");
ofstream fout("grupuri.out");

int tabla[105][105], n, grupuri;

void rezolvare(int linie, int coloana) {
    if(1 <= linie && linie <= n && 1 <= coloana && coloana <= n) {
        if(tabla[linie][coloana] == 1) {
            tabla[linie][coloana] = 0;

            rezolvare(linie, coloana + 1);
            rezolvare(linie, coloana - 1);
            rezolvare(linie + 1, coloana);
            rezolvare(linie - 1, coloana);
        }
    }
}

int main() {

    fin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fin >> tabla[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(tabla[i][j]) {
                grupuri++;
                rezolvare(i, j);
            }
        }
    }

    fout << grupuri;
    return 0;
}
