#include <fstream>
using namespace std;

ifstream fin ( "placare1.in" );
ofstream fout ( "placare1.out" );

int cmmdc ( int x, int y ){
    int r = x % y;
    while ( r != 0 ){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main(){

    int L, A, B, Sol = -1;

    fin >> L >> A >> B;

    Sol = max ( ( A * B / cmmdc( A, L ) ), ( A * B / cmmdc( B, L ) ) );

    fout << Sol;

    return 0;
}
