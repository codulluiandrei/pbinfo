/*
    Autor: prof. Alin Burta, Colegiul Național "B.P. Hasdeu", Buzau
*/
#include <iostream>
#include <fstream>
#define FIN "raza.in"
#define FOU "raza.out"
#define SMAX 10001              //maximum de rovere
#define SecMax 100001           //maximum de secunde
using namespace std;
int Prd[SMAX];
int S;                          //numarul roverelor
int M;                          //numarul roverelor ramase
int Sec;                        //numar maxim secunde
int Unu[SMAX], Doi[SMAX];       //intersectia cu diagonale
int C1[SecMax], C2[SecMax];
int Cate[SecMax];
int main()
{
    ifstream in(FIN);
    int i, j,  M, x, y, r ;
    int minim, maxim, aux, timp;
    int task;
    minim = SecMax+ 1;
    maxim = -1;
    //citire date de intrare
    in >> task >> S >> Sec;
    M = 0;
    for( i = 1; i <= S; ++i )
    {
        in >> x >> y >> r;
        //verific daca se intersecteaza cu diagonala
        if( x <= y + r - 1 && x + r - 1 >= y )
        {
            M++;
            Prd[M] = 4 * r - 4;
            // calculez intersectiile fiecaei traiectorii cu diagonala
            if( x == y )    //varfurile pe diagonala
            {
                Unu[M] = 1;
                Doi[M] = 2 * r - 1;
            }
            else
                if( x > y ) //intersectie cu prima si a doua latura
                {
                    Unu[M] = x - y + 1;
                    Doi[M] = 2 * r + y - x - 1 ;
                }
                else // intersectie cu celelalte doua laturi
                {
                    Unu[M] = 2 * r + y - x - 1; //2 * r - 2 + y  + r - 1 - ( x + r - 1) + 1;
                    Doi[M] = 4 * r - y + x - 3;
                }
            if( Unu[M] == Doi[M] )
                Doi[M] = 0;
            if( Unu[M] > maxim )
                maxim = Unu[M];
            if( Unu[M] < minim )
                minim = Unu[M];
            if( Doi[M] > maxim && Doi[M] )
                maxim = Doi[M];
            if( Doi[M] < minim && Doi[M] )
                minim = Doi[M];
        }
    }
    in.close();
    for( i = 1; i <= M; ++i )
        C1[i] = Unu[i], C2[i] = Doi[i];
    for( i = 1; i <= Sec; ++i)
        Cate[i] = 0;
    for( i = 1; i <= M; ++i )
    {
        for(j = C1[i]; j <= Sec; j += Prd[i])
            Cate[j]++;
        if( Doi[i] )
            for(j = C2[i]; j <= Sec; j += Prd[i])
                Cate[j]++;
    }
    maxim = 0;
    timp  = 0;
    for( i=1; i <= Sec; ++i )
        if( maxim < Cate[i] )
            maxim = Cate[i], timp = i;
    ofstream out(FOU);
    if(task == 1)
        out << M << '\n';
    else
        out << maxim << " " << timp << '\n';
    out.close();
    return 0;
}