/*  Implementare: Cristi Dospra
	Punctaj: 100p
	Utilizat: Mars + Fill(cu coada) + fstream
	Complexitate: O( N*M + R )
*/
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
#define Nmax 2002
ifstream fin ( "meteoriti.in" );
ofstream fout ( "meteoriti.out" );
int Mars[Nmax][Nmax], Nr, N, M, R;
bool viz[Nmax][Nmax];
const int dir[4][2] = { { -1,0 }, { 0,1 }, { 1,0 }, { 0,-1 } };
queue < pair < int , int > > Q;
bool Inside ( int x, int y ){
    if ( x > 0 && x <= N && y > 0 && y <= M )
        return 1;
    return 0;
}
void Fill ( int x, int y, int h ){
    Q.push ( make_pair(x,y) );
    viz[x][y] = 1;
    while ( !Q.empty() ){
        int x = Q.front().first;
        int y = Q.front().second;
        Nr++;
        Q.pop();
        for ( int i = 0; i < 4; ++i ){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if ( Inside ( xx, yy ) && !viz[xx][yy] && Mars[xx][yy] == h ){
                Q.push ( make_pair(xx, yy) );
                viz[xx][yy] = 1;
            }
        }
    }
}
int main(){
    fin >> N >> M >> R;
    int x1, y1, x2, y2, c;
    while ( R-- ){
        fin >> x1 >> y1 >> x2 >> y2 >> c;
        Mars[x1][y1] += c;
        Mars[x2+1][y1] -= c;
        Mars[x1][y2+1] -= c;
        Mars[x2+1][y2+1] += c;
    }
    for ( int i = 1; i <= N; ++i )
        for ( int j = 1; j <= M; ++j )
            Mars[i][j] += Mars[i-1][j] + Mars[i][j-1] - Mars[i-1][j-1];
    int MaxArea = -1, MaxHeight = -1, UnTouched = 0;
    for ( int i = 1; i <= N; ++i ){
        for ( int j = 1; j <= M; ++j ){
            if ( !viz[i][j] ){
                Nr = 0;
                Fill ( i, j, Mars[i][j] );
                if ( Mars[i][j] == 0 )
                    UnTouched += Nr;
                else{
                    if ( Mars[i][j] > MaxHeight ){
                        MaxHeight = Mars[i][j];
                        MaxArea = Nr;
                    }
                    else if ( Mars[i][j] == MaxHeight && Nr > MaxArea )
                        MaxArea = Nr;
                }
            }
        }
    }
    fout << MaxArea << " " << UnTouched;
    return 0;
}