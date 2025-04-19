// Implementare: Cristi Dospra
// Punctaj: 100p
// Complexitate: ( N * log Ture )
#include <fstream>
#include <cmath>
using namespace std;
#define Nmax 1000002
ifstream fin ( "bomboane2.in" );
ofstream fout ( "bomboane2.out" );
long long v[Nmax];
int main(){
    long long N, MaxVal = -1;
    fin >> N;
    for ( int i = 1; i <= N; ++i ){
        fin >> v[i];
        MaxVal = max ( MaxVal, v[i] );
    }
    long long Ture, st = 0, dr = sqrt ( double ( MaxVal ) ) * sqrt(double(2)) ;
    while ( st <= dr ){
        long long mid = ( st + dr ) >> 1;
        bool ok = 1;
        for ( int i = 1; i <= N; ++i ){
            if ( v[i] < mid * i + ( N * mid * (mid-1) ) / 2 ){
                ok = 0;
                break;
            }
        }
        if ( ok ){
            Ture = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }
    N *= Ture;
    fout << ( N * (N+1) / 2 );
    return 0;
}