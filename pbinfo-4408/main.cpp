///In scop demonstrativ, aceasta implementare nu foloseste functii sau siruri
///Complexitate O(n*sqrt(a1)) timp, O(1) memorie
#include <fstream>
#include <iostream>
#define DURATA_ORA 60
#define NR_ORE_PE_ZI 24
using namespace std;
ifstream fi("aeriana.in");
ofstream fo("aeriana.out");
int main(){
    int C, N, a1, a2, h1, m1, h2, m2;
    int durata_maxima_in_minute = 0; /// este garantat ca orice zbor va dura cel putin un minut
    int durata_curenta_in_minute;
    int momentul_1_in_minute;
    int momentul_2_in_minute;
    bool interschimbam = false;
    bool prim;
    int suma;
    int contor_interschimbari = 0;
    fi>>C>>N;
    for(int i=1;i<=N;i++){
        fi>>a1>>a2>>h1>>m1>>h2>>m2;
        /// pentru cerinta 1, a1 si a2 pot fi ignorate
        if (C == 2) {
            ///pentru cerinta 2, avem urmatorul algoritm care verifica daca un zbor e "special"
            if (a1 < 2) {
                prim = false;
            } else {
                prim = true;
                for(int d=2;prim && d*d<=a1;d++){
                    if (a1 % d == 0){
                        prim = false;
                    }
                }
            }
            if(prim) {
                /// in cazul in care a1 e prim, aflam suma cifrelor acestuia
                suma = 0;
                while(a1 > 0){
                    suma += a1%10;
                    a1 /= 10;
                } 
                if(a2 % suma== 0){
                    interschimbam = true;
                }else{
                    interschimbam = false;
                }
            } else {
                interschimbam = false;
            }
            if (interschimbam) {
                swap(h1,h2); /// efectuam interschimbarea si aflam maximul intocmai precum la cerinta 1
                swap(m1,m2);
            }
        }
        momentul_1_in_minute = h1 * DURATA_ORA + m1; /// momentele 1 si 2 se convertesc in numarul
        momentul_2_in_minute = h2 * DURATA_ORA + m2; /// de minute ce au trecut incepand cu 00:00, prima zi
        durata_curenta_in_minute = momentul_2_in_minute - momentul_1_in_minute;
        if(durata_curenta_in_minute < 0){ /// suntem in cazul cand zborul aterizeaza a doua zi
            durata_curenta_in_minute += NR_ORE_PE_ZI *DURATA_ORA; /// deci adunam 24*60 pentru conversia celui de-al doilea moment
        }
        durata_maxima_in_minute = max(durata_maxima_in_minute, durata_curenta_in_minute);
    }
    int durata_ore = durata_maxima_in_minute / DURATA_ORA;
    int durata_minute = durata_maxima_in_minute % DURATA_ORA;
    fo<<durata_ore<<' '<<durata_minute<<'\n';
    fi.close();
    fo.close();
    return 0;
}