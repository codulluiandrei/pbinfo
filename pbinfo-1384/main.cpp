#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;
#define NN 205
ifstream fin("cladire5.in");
ofstream fout("cladire5.out");
int n, m, a[NN][NN], s[NN][NN] , S;
int main(){
        assert(fin >> n >> m >> S);
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=m ; j++)
                assert(fin >> a[i][j]);
        s[1][m] = a[1][m];
        for(int i=2;i<=n;++i)
            s[i][m] = s[i-1][m] + a[i][m];
        for(int j=m-1 ; j >= 1 ; --j)
            s[1][j] = s[1][j+1] + a[1][j];
        for(int i = 2 ; i<=n ; ++i)
            for(int j = m - 1 ; j>=1 ; --j)
                if(s[i-1][j] <s[i][j+1])
                    s[i][j] = s[i-1][j] + a[i][j];
                else
                    s[i][j] = s[i][j+1] + a[i][j];
        fout << S - s[n][1] << "\n";
	return 0;
}