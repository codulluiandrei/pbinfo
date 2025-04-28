#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("castel2.in");
ofstream fout("castel2.out");
const int DIM = 1000,
          di[]={1,-1,0,0},
          dj[]={0,0,1,-1};
int  n , m , k;
int A[DIM + 1][DIM + 1], B[DIM + 1][DIM + 1];
int main(){
    fin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1; j <= m ; j ++)
        {
            char x;
            fin >> x;
            if(x == '-')
                A[i][j] = 0;
            if(x == '#')
                A[i][j] = -1;
            if(x == 'Z')
                A[i][j] = 1;
        }
    queue<pair<int,int>> Q;
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            if(A[i][j] == 1)
                Q.push({i,j});
    while(!Q.empty())
    {
        int i = Q.front().first, j = Q.front().second;
        Q.pop();
        if(A[i][j] <= k)
            for(int p = 0 ; p < 4 ; p ++)
            {
                int x = i+di[p], y = j+dj[p];
                if(x > 0 && x <= n && y > 0 && y <= m && A[x][y] == 0)
                    A[x][y] = A[i][j] + 1, Q.push({x,y});
            }
    }
    Q.push({1,1});
    B[1][1]=1;
    while(!Q.empty())
    {
        int i = Q.front().first, j = Q.front().second;
        Q.pop();
        for(int p = 0 ; p < 4 ; p ++)
        {
            int x = i + di[p], y = j + dj[p];
            if(x > 0 && x <= n && y > 0 && y <= m && A[x][y] == 0 && B[x][y] == 0)
                B[x][y] = B[i][j] + 1, Q.push({x,y});
        }
    }
    if(B[n][m] == 0)
        B[n][m] = -1;
    fout << B[n][m];
    cout << B[n][m] << endl;
}