// implementare: Cristi Dospra
// punctaj: 100p
// complexitate: O(N * M)
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define Nmax 1002
#define inf 0x3f3f3f3f
ifstream fin ( "brutar.in" );
ofstream fout ( "brutar.out" );
int N, M;
char v[Nmax][Nmax];
int Dist[Nmax][Nmax];
pair < int, int > Pred[Nmax][Nmax];
vector < pair < int, int > > Coords;
queue < pair < int, int > > Q;
bool Valid ( int x, int y ){
    if ( x > 0 && x <= N && y > 0 && y <= M && v[x][y] != 'X' )
        return 1;
    return 0;
}
void Lee(){
    for ( int i = 1; i <= M; ++i ){
        if ( v[1][i] == 'O' ){
            Q.push( make_pair( 1, i ) );
            Dist[1][i] = 1;
        }
    }
    while ( !Q.empty() ){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        vector < pair < int, int > > :: iterator it;
        for ( it = Coords.begin(); it != Coords.end(); ++it ){
            int xx = x + it->first;
            int yy = y + it->second;
            if ( Valid(xx,yy) && Dist[xx][yy] > Dist[x][y] + 1 ){
                Q.push( make_pair(xx,yy) );
                Dist[xx][yy] = Dist[x][y] + 1;
                Pred[xx][yy] = make_pair( x, y );
            }
        }
    }
}
void Remake ( int x, int y ){
    if ( !x || !y )
        return;
    Remake( Pred[x][y].first, Pred[x][y].second );
    fout << x << " " << y << "\n";
}
void Read(){
    int x, y;
    char a, b;
    fin >> N >> M;
    for ( int i = 1; i <= N; ++i ){
        fin >> ( v[i] + 1 );
        for ( int j = 1; j <= M; ++j ){
            Dist[i][j] = inf;
        }
    }
    Coords.push_back ( make_pair( -1, 0 ) );
    Coords.push_back ( make_pair( 0, 1 ) );
    Coords.push_back ( make_pair( 1, 0 ) );
    Coords.push_back ( make_pair( 0, -1 ) );
    for ( int i = 1; i <= 2; ++i ){
        fin >> x >> a >> y >> b;
        if ( a == 'N' )
            x = -x;
        if ( b == 'V' )
            y = -y;
        Coords.push_back( make_pair( x, y ) );
    }
}
void Write(){
    int Best = inf;
    pair < int, int > Sol;
    for ( int i = 1; i <= M; ++i ){
        if ( Dist[N][i] < Best ){
            Best = Dist[N][i];
            Sol = make_pair( N, i );
        }
    }
    fout << Best << "\n";
    Remake( Sol.first, Sol.second );
}
int main(){
    Read();
    Lee();
    Write();
    return 0;
}