#include <fstream>
using namespace std;
ifstream fin ( "clatite.in" );
ofstream fout ( "clatite.out" );
#define ciocolata 0
#define gem 1
#define inghetata 2
#define zahar 3
#define simpla 4
int TipClatita[5];
int main(){
    int N, M;
  	fin >> N >> M;
    for ( int i = N; i <= M; ++i ){
        int x = i, power, term, SumaDiv = 1, NrDiv = 1;
        bool PP = 1, CP = 1;
        for ( int j = 2; j * j <= x; ++j ){
            term = j;
            power = 0;
            while ( x % j == 0 ){
                x /= j;
                power++;
                term *= j;
            }
            if ( power % 2 )
                PP = 0;
            if ( power % 3 )
                CP = 0;
            NrDiv *= ( power + 1 );
            if ( power )
                SumaDiv *= ( ( term - 1 ) / ( j - 1 ) );
        }
        if ( x > 1 ){
            PP = CP = 0;
            NrDiv *= 2;
            SumaDiv *= ( ( x * x - 1 ) / ( x - 1 ) );
        }
        if ( NrDiv == 2 ){
            TipClatita[ciocolata]++;
            continue;
        }
        if ( PP || CP ){
            TipClatita[gem]++;
            continue;
        }
        if ( SumaDiv - i == i ){
            TipClatita[inghetata]++;
            continue;
        }
        if ( i & 1 )
            TipClatita[simpla]++;
        else
            TipClatita[zahar]++;
    }
  	fout << M - N + 1 << "\n";
    for ( int i = 0; i < 5; ++i )
      	fout << TipClatita[i] << " ";
    return 0;
}