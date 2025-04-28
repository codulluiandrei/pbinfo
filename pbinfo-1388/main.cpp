/**
*****Restrictii*****
n <= 9.000.000
Timp de executie: 2 sec
Limita memorie: 5 Mb
Un vector de frecventa clasic ar folosi 34.33 Mb
Cei doi vectori de frecventa pe biti ar folosi 2.14 Mb.
*/
/**
Problema Colectie - Constantinescu Eduard
Se da un sir de n numere naturale mai mici sau egale cu n.
Sa se determine cate din numerele sirului nu se repeta.
Folosirea unui vector clasic de frecventa pentru a memora aparitiile numerelor din sir
duce la depasirea limitelor impuse. Chiar si cu mici optimizari, limitele sunt prea dure
pentru a apela la aceasta metoda.
Vom folosi doi vectori de tip unsigned int, de lungime "n/32 + 1". Fiecare element al vectorului
este un int cu 32 de biti. Astfel, elementul f1[0] va deveni un "vector" de 32 de elemente de
tip 1 si 0. (De exemplu, aparitia numarului 3 se va afla pe al 3-lea bit din elementul v[0],
iar aparitia numarului 35 se va afla pe al 3-lea bit din elementul v[1]). Ne folosim de 2 vectori
de frecventa pentru a marca aparitiile unui numar in sir. La prima aparitie a acestuia, schimbam
in primul vector bitul corespunzator numarului gasit. La a doua aparitie, schimbam in al doilea vector
bitul corespunzator. Este suficient sa marcam 2 aparitii ale aceluiasi numar.
La final, parcurgem tot vectorul si incrementam un contor in momentul in care gasim un numar care este marcat
in primul vector, dar nu si in al doilea.
Ne vom folosi de un vector de 32 de elemente, care reprezinta mastile cu care vom verifica valoarea bitilor.
*/
#include <cstdio>
#define NMAX 313000
using namespace std;
FILE *fin = fopen("colectie.in", "r");
FILE *fout = fopen("colectie.out", "w");
unsigned int masca[33], n, el, poz_f, poz_m,  k;
unsigned int f1[NMAX + 2], f2[NMAX + 2];
void calc_puteri() ///calculam mastile folosite pt a verifica valoarea bitilor
{
    masca[0] = 1;
    for(int i = 1; i <= 32; i++)
        masca[i] = masca[i-1]<<1;
}
int main()
{
    calc_puteri(); ///calcularea mastilor
    fscanf(fin, "%d", &n); ///citim n
    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d", &el); ///citim un numar din sir
        poz_f = el / 32; /// calculam pozitia in vectorul de frecventa
        poz_m = el % 32; /// acesta este bitul pe care il vom verifica
        if((f1[poz_f] & masca[poz_m]) == 0) ///daca nu a fost deloc intalnit
            f1[poz_f] |= masca[poz_m]; ///ii marcam aparitia in primul vector
        else if((f2[poz_f] & masca[poz_m]) == 0) ///daca l-am intalnit deja
            f2[poz_f] |= masca[poz_m];  ///ii marcam aparitia in al doilea vector
    }
    for(int i = 0; i <= n / 32; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(((f1[i] & masca[j]) != 0) && ((f2[i] & masca[j]) == 0))
                ++k; ///daca apare in primul vect si nu apare in al doilea
                    ///inseamna ca numarul nu se repeta
        }
    }
    fprintf(fout, "%d\n", k); ///afisam contorul
    return 0;
}