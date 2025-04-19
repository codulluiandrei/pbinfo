// implementare: Cristi Dospra
// punctaj: 20p
// complexitate: O(2^N * N )
#include <fstream>
using namespace std;
#define Nmax 100002
#define inf 2000000000
ifstream fin ( "democratie.in" );
ofstream fout ( "democratie.out" );
int N, T1, T2, C1, C2;
int v[Nmax], Sol = inf;
int config[Nmax];
void bkt ( int poz ){
    if ( poz > N ){
        int st = 1, dr = N;
        int Total = 0;
        for ( int i = 1; i <= N; ++i ){
            if ( config[i] == 1 ){
                Total += v[st] * T1;
                st++;
                if ( config[i-1] == config[i] )
                    Total += C1;
            }
            else{
                Total += v[dr] * T2;
                dr--;
                if ( config[i-1] == config[i] )
                    Total += C2;
            }
        }
        Sol = min ( Sol, Total );
        return ;
    }
    for ( int i = 1; i <= 2; ++i ){
        config[poz] = i;
        bkt ( poz + 1 );
    }
}
int main(){
    fin >> N;
    for ( int i = 1; i <= N; ++i )
        fin >> v[i];
    fin >> T1 >> T2 >> C1 >> C2;
    bkt ( 1 );
    fout << Sol;
    return 0;
}