#include <fstream>
using namespace std;
#define Nmax 5002
ifstream fin ( "bosumflat.in" );
ofstream fout ( "bosumflat.out" );
int grad[Nmax];
struct Numar{
    int impar, par;
}v[Nmax];
int Par ( int x ){
    return x / 1000000 % 10 * 1000 + x / 10000 % 10 * 100 + x / 100 % 10 * 10 + x % 10;
}
int Impar ( int x ){
    return x / 10000000 % 10 * 1000 + x / 100000 % 10 * 100 + x / 1000 % 10 * 10 + x / 10 % 10;
}
bool Bosumflat ( int x, int y ){
    return ( v[x].impar < v[y].par && v[x].par > v[y].impar );
}
int main(){
    int N, x;
    fin >> N;
    for ( int i = 1; i <= N; ++i ){
        fin >> x;
        v[i].par = Par (x);
        v[i].impar = Impar (x);
    }
    for ( int i = 1; i < N; ++i )
        for ( int j = i+1; j <= N; ++j )
            {
                grad[i] += Bosumflat ( i, j );
                grad[j] += Bosumflat ( j, i );
            }
    for ( int i = 1; i <= N; ++i )
        fout << grad[i] << " ";
}