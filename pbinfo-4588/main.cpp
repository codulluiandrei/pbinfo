//Serban Marinel - ianuarie 2024
#include <bits/stdc++.h>
#define L 20241
using namespace std;
ifstream fin("pin.in");
ofstream fout("pin.out");
char randul[L];        //maxim 2024 numere a cate 9 cifre + 1 spatiu intre ele
char pin[1001];        //aici voi construi pin-ul
int lgpin;             //lungime pin - daca depaseste 4 - stop nu-i bun
int lgrand;            //numar cifre in rand
int R, r, i, c;
int main()
{
    fin >> R;                   //numar randuri
    fin.get();
    for (r = 1; r <= R; ++r)    //pentru fiecare rand
    {
        fin.getline(randul, L); //citesc tot randul
        int cifre[10] = {0};    //pun pe 0 un vector de aparitii
        lgrand = 0;
        i = 0;                  //plec de la inceputul randului
        while (randul[i] != 0)  //daca nu am ajuns la sfarsitul randului
        {
            if (randul[i] != ' ')//daca e cifra
            {
                ++lgrand;        //numar cifra
                c = randul[i] - 48;//determin cifra
                ++cifre[c];      //si o numar
            }
            ++i;                 //trec la alt caracter
        }
        for (c = 0; c < 10; ++c)
            if (cifre[c] > lgrand / 2) //c este element majoritar
            {
                pin[lgpin] = (char)(c + 48);//il adaug la pin
                lgpin++;                    //si numar
            }
    }
    pin[lgpin] = 0;                         //inchei sirul pin
    if (lgpin == 4)                         //daca are exact 4 cifre
        fout << "PIN CORECT " << pin << '\n';//este corect
    else
        fout << "PIN INCORECT " << pin << '\n';//este incorect
    return 0;
}