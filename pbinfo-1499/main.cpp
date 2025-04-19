#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("broscute.in");
ofstream fout("broscute.out");
#define DIM 1004
struct mutari {
    int b, s, d;                   // b - nr broscutei   s - de unde a plecat    d - unde a ajuns
} Mutari[DIM * 10];
int n, c, pozA[DIM], pozB[DIM], V[DIM], Final[DIM];
/*
    V - Configuratia actuala
    Final - Configuratia finala
    PozA[i] - pozitia broscutei i din configuratia actuala
    PozB[i] - pozitia broscutei i din configuratia finala
*/
int main() {
    fin >> n>> c;                  // Citim numarul de broscute si tipul cerintei
    ++n;                           // Nr de Frunze = Nr de Broscute + 1
    for(int i = 1; i <= n; ++i) {
        fin >> V[i];               // Citim configuratia initiala
        pozA[V[i]] = i;            // Si construim vectorul PozA
    }
    for(int i = 1; i <= n; i++){   // Citim configuratia finala
        fin >> Final[i];           // si construim vectorul PozB
        pozB[Final[i]] = i;
    }
    int okey = 1;                  // Presupunem ca inca n-am ajuns la configuratia finala
    int mutari = 0;                // Initial, numarul de mutari este 0
    while(okey == 1) {             // Cat timp n-am ajuns la configuratia finala
        okey = 0;
        if(Final[pozA[0]] != 0) {  // Daca pozitiile frunzei libere nu corespund in cele doua configuratii
            okey = 1;
            ++mutari;
            Mutari[mutari].b = Final[pozA[0]],        //
            Mutari[mutari].s = pozA[Final[pozA[0]]],  //
            Mutari[mutari].d = pozA[0];               // --> Aducem pe pozitia frunzei libere din configuratia noastra
            swap(pozA[0], pozA[Final[pozA[0]]]);      //     broscuta care trebuia sa fie pe acea pozitie in configuratia
            swap(V[pozA[0]], V[pozA[Final[pozA[0]]]]);//     finala
        }
        else {                                        // Daca pozitiile frunzei libere din cele doua configuratii corespund
            for(int i = 1; i < n; ++i) {              // Verificam daca avem broscute care nu sunt pe pozitiile corespunzatoare
                if(pozA[i] != pozB[i]) {              // Daca broscuta i se afla pe o alta pozitie decat cea care ar trebui
                    okey = 1;
                    ++mutari;
                    Mutari[mutari].b = V[pozA[i]],    //
                    Mutari[mutari].s = pozA[i],       //
                    Mutari[mutari].d = pozA[0];       // ---> O mutam pe pozitia frunzei libere
                    swap(pozA[0], pozA[i]);           //
                    swap(V[pozA[0]], V[pozA[i]]);     //
                    break;
                }
            }
        }
    }
    if(c == 1) {                                      // Daca tipul de cerinta este 1
        fout << mutari << '\n';                       // Afisam numarul de mutari
    }
    else {                                            // Daca tipul de cerinta este 2
        if(mutari == 0) {
            fout << "broscutele nu se joaca\n";
        }
        else {
            for(int i = 1; i <= mutari; ++i) {        // Afisam mutarile
                fout << Mutari[i].b << ' ' << Mutari[i].s << ' ' << Mutari[i].d << '\n';
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}