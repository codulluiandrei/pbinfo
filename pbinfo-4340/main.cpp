//Serban Marinel
#include <fstream>
#include <algorithm>
using namespace std;
#define KMAX 101
#define NMAX 1001
ifstream fin("hotel.in");
ofstream fout("hotel.out");
struct hotel
{
    int camera;
    int zi;
    int pers;
    bool carantinat;
} H[NMAX];
int k, m, n, zi_curenta, nr_pacienti, cerinta, z, cazati[NMAX];
void citeste()
{
    // citeste datele de intrare
    int i;
    fin >> cerinta;
    fin >> k >> m >> n >> z;
    for (i = 1; i <= n; i++)
    {
        fin >> H[i].zi;                    //din ce este solicitata cazarea
        H[i].pers = i;                     //persoanei i
    }
}
void elib_camere(int ziua)
{
    // elibereaza camere pana in ziua
    int i;
    for (i = 1; i <= k; i++)
        if(H[i].camera <= ziua) H[i].camera = 0;
}
int det_primacam()
{
    // determina prima camera libera
    int i;
    for (i = 1; i <= k; i++)
        if (H[i].camera == 0) return i;
    return 0;
}
void cazeaza()
{
    int i = 1, j;
    nr_pacienti = 0;
    zi_curenta = H[i].zi;                     //plec cu prima solicitare
    while (i <= n && zi_curenta + m - 1 <= z) //mai am si solicitarea este buna
    {
        elib_camere(zi_curenta);              //sunt ordonate deci eliberez camerele pana aici
        j = det_primacam();                   //caut prima camera libera
        if (j > 0 && zi_curenta + m - 1 <= z) //am gasit o camera libera si pot caza
        {
            H[j].camera = zi_curenta + m;     //pana aici camera va fi ocupata
            nr_pacienti++;                    //inca un pacient cazat
            cazati[nr_pacienti] = H[i].pers;  //care pacient (pentru cerinta 2)
            H[i].carantinat = true;
        }
        i++;                                  //trec la urmatoarea zi solicitata
        zi_curenta = H[i].zi;                 //aici incepe solicitarea
    }
}
bool persoana(hotel A, hotel B)
{
    return (A.pers < B.pers);
}
bool criteriu(hotel A, hotel B)
{
    if (A.zi < B.zi)
        return 1;
    else
        return 0;
}
void ordonare()
{
    stable_sort(H + 1, H + n + 1, criteriu);  // ordonare crescatoare solicitari
}                                            //cu pastrarea ordinii relative
void afisare()
{
    int i, ic = 0, sc = 0, primul = 0, lmax = 0;
    if (cerinta == 1)
        fout << nr_pacienti << '\n';
    else
        if (cerinta == 2)
        {
            for (i = 1; i <= nr_pacienti; i++) fout << cazati[i] << ' ';
            fout << '\n';
        }
        else
        {
            sort(H + 1, H + n + 1, persoana);
            i = 1;
            while (i <= n)
            {
                while (H[i].carantinat == true && i <= n) i++;
                if (i < n)
                {
                    ic = i;
                    sc = i + 1;
                    while (H[sc].carantinat == false && sc <= n) sc++;
                    if (sc - ic > lmax)
                    {
                        lmax = sc - ic;
                        primul = ic;
                    }
                    i = sc;
                }
            }
            fout << lmax << ' ' << primul << '\n';
        }
}
int main()
{
    citeste();
    ordonare();
    cazeaza();
    afisare();
    return 0;
}