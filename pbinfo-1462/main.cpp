#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define Nmax 100002
#define Mod 666013

ifstream fin ( "gasti.in" );
ofstream fout ( "gasti.out" );

vector < int > G[Nmax];
int Gasca[Nmax], Members[Nmax], Cate[Nmax];

int cnt = 0;
void DFS ( int node, int gasca ){

    cnt++;
    Gasca[node] = gasca;

    vector < int > :: iterator it;
    for ( it = G[node].begin(); it != G[node].end(); ++it ){
        if ( !Gasca[*it] )
            DFS ( *it, gasca );
    }
}

int main(){

    int N, M;

    fin >> N >> M;
    for ( int i = 1; i <= M; ++i ){
        int x, y;
        fin >> x >> y;
        G[x].push_back ( y );
        G[y].push_back ( x );
    }

    int gasti = 0, max1 = -1, max2 = -1;
    for ( int i = 1; i <= N; ++i ){
        if ( !Gasca[i] ){
            cnt = 0;
            DFS ( i, ++gasti );
            Members[gasti] = cnt;
            Cate[Members[gasti]]++;

            if ( Members[gasti] > max1 ){
                max2 = max1;
                max1 = Members[gasti];
            }
            else if ( Members[gasti] > max2 )
                max2 = Members[gasti];
        }
    }

    long long x, y;
    if ( max1 != max2 ){
        x = ( 1LL * Cate[max1] * max1 ) % Mod;
        y = ( 1LL * Cate[max2] * max2 ) % Mod;
    }
    else{
        x = ( 1LL * max1 * max1 ) % Mod;
        y = ( 1LL * Cate[max1] * ( Cate[max1]-1 ) / 2 ) % Mod;
    }
    long long rez = ( x * y ) % Mod;

    fout << gasti << " " << rez;

    return 0;
}

