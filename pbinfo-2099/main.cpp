//marinel serban - ianuarie 2013
#include <fstream>
using namespace std;
ifstream fin("unupatru.in");
ofstream fout("unupatru.out");
int n, i, nr_op, uc;
long long x, s2;
int main()
{
    fin >> n;                      //numarul de numere
    for (i = 1; i <= n; i++)       //pentru fiecare numar
    {
        fin >> x;                     //il citesc in x
        nr_op = 0;                    //initializez numarul de operatii
        while (x != 1 && x != 4)      //cat timp nu am obtinut 1 sau 4
        {
            s2 = 0;                     //initializez suma patratelor cu 0
            nr_op++;                    //contorizez calculul
            while (x)                   //cat timp mai exista cifre in x
            {
                uc = x % 10;              //scot ultima cifra
                s2 += uc * uc;            //adun patratul cifrei
                x /= 10;                  //scap de ea
            }
            x = s2;                     //s2 este noul x
        }
        if (i < n)                    //daca i < n nr_op trebuie urmat de spatiu
            fout << nr_op << ' ';
        else
            fout << nr_op << '\n';    //altfel (ultimul numar) se termina cu '\n'
    }
    fout.close();
    return 0;
}