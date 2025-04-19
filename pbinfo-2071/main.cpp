///sursa oficiala - prof. Alin Burta
#include <fstream>
#define Nmax 100001         //numarul maxim de puncte
#define Cmax 1001           //coordonata maxima
#define IN "triunghiuri2.in"
#define OU "triunghiuri2.out"
using namespace std;
long N;                     //numarul punctelor
long long NrTr;                  //numarul triunghiurilor gasite
short nx[Cmax];             // nx[i] - cate puncte sunt pe absisa i
short ny[Cmax];             // ny[i] - cate puncte sunt pe ordonata i
short H[Cmax][Cmax];        //memorez punctele ordonate  H[i] - lista punctelor cu ordonata i
long long aux, aux1, aux2,  sumLin;
int main()
{
    long int i, j, Max, V;
    short x, y;
    //citire date
    ifstream Fin(IN);
    Fin >> V >> N;
    for(i = 0; i <= Cmax - 1; ++i) nx[i] = ny[i] = 0;
    for(i = 1; i <= N; ++i)
    {
        Fin >> x >> y;
        nx[x]++; ny[y]++;
        H[ y ][ ny[y] ] = x;
    }
    Fin.close();
    if( V == 1)
    {
        Max = 0;
        for(i = 0; i <= 999; ++i)
            if(nx[i] > Max)
                Max = nx[i];
        ofstream Fou(OU);
        Fou << Max << '\n';
        Fou.close();
    }
    else
    {
        NrTr = 0;
        for( i = 0; i< Cmax-1; ++i)
        if(ny[i] > 1)
        {
            sumLin = 0;
            for(j = 1; j<=  ny[i]; ++j) sumLin +=  ( nx[ H[i][j] ] - 1 ) * (ny[i] - 1);
            aux1 = ( ny[i] * (ny[i] - 1) / 2 );
            aux2 = ( N - ny[i]);
            aux = aux1 * aux2;
            NrTr +=  aux  - sumLin ;
            NrTr %= 1000003;
        }
        ofstream Fou(OU);
        Fou << NrTr << '\n';
        Fou.close();
    }
    return 0;
}