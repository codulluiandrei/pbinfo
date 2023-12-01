//Serban Marinel - ianuarie 2013
//solutie fara utilizarea vectorilor
#include <fstream>

using namespace std;

ifstream fin("chibrituri.in");
ofstream fout("chibrituri.out");

bool OK1;
short int t, h1, h2, m1, m2, v, o, vOK, oOK, Cate;
short int h1min, h2min, m1min, m2min;
short int h1max, h2max, m1max, m2max;

int main()
{
    fin >> vOK >> oOK;
    t = 0;               //plec de la ora 00:00
    OK1 = false;         //inca nu am gasit nici o ora corecta
    Cate = 0;
    while (t < 24 * 60)  //intr-o zi sunt 24*60 minute
    {                    //trec pe la fiecare
        m1 = t % 60;     //ora
        h1 = t / 60;     //minute
        h2 = h1 % 10;    //a doua cifra a orei
        h1 = h1 / 10;    //prima cifra a orei
        m2 = m1 % 10;    //a doua cifra a minutului
        m1 = m1 / 10;    //prima cifra a minutului

        v = 0;           //numar chibrituri verticale
        switch (h1)
        {
            case 1:
            case 2:
            case 3:
            case 5:
            case 7: v += 2; break;
            case 4:
            case 6:
            case 9: v += 3; break;
            case 0:
            case 8: v += 4; break;
        }
        switch (h2)
        {
            case 1:
            case 2:
            case 3:
            case 5:
            case 7: v += 2; break;
            case 4:
            case 6:
            case 9: v += 3; break;
            case 0:
            case 8: v += 4; break;
        }
        switch (m1)
        {
            case 1:
            case 2:
            case 3:
            case 5:
            case 7: v += 2; break;
            case 4:
            case 6:
            case 9: v += 3; break;
            case 0:
            case 8: v += 4; break;
        }
        switch (m2)
        {
            case 1:
            case 2:
            case 3:
            case 5:
            case 7: v += 2; break;
            case 4:
            case 6:
            case 9: v += 3; break;
            case 0:
            case 8: v += 4; break;
        }

        o = 0;          //numar chibrituri orizontale
        switch (h1)
        {
            case 1: o += 0; break;
            case 4:
            case 7: o += 1; break;
            case 0: o += 2; break;
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9: o += 3; break;
        }
        switch (h2)
        {
            case 1: o += 0; break;
            case 4:
            case 7: o += 1; break;
            case 0: o += 2; break;
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9: o += 3; break;
        }
        switch (m1)
        {
            case 1: o += 0; break;
            case 4:
            case 7: o += 1; break;
            case 0: o += 2; break;
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9: o += 3; break;
        }
        switch (m2)
        {
            case 1: o += 0; break;
            case 4:
            case 7: o += 1; break;
            case 0: o += 2; break;
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9: o += 3; break;
        }

        if (v == vOK && o == oOK)  //daca am gasit ambele valori corecte
            {
                Cate++;     //mai am o solutie, o numar
                if (!OK1)   //prima gasita? deci este ora minima, retin
                    {
                        h1min = h1, h2min = h2, m1min = m1, m2min = m2;
                        OK1 = true;
                    }
                else        //am mai gasit deci este (deocamdata) ora maxima
                  h1max = h1, h2max = h2, m1max = m1, m2max = m2;
            }
        t++;                //trec la ora (minutul) urmatoare
    }
    fout << Cate << '\n';
    fout << h1min << h2min << ':' << m1min << m2min << '\n';
    if (Cate == 1)  //daca am doar o solutie, aceasta este si ora maxima
        fout << h1min << h2min << ':' << m1min << m2min << '\n';
    else
        fout << h1max << h2max << ':' << m1max << m2max << '\n';

    fout.close();
    return 0;
}
