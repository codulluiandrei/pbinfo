//Solutie problema Matrice
//programare dinamica
//Complexitate N*N
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define dim 1009
using namespace std;
ofstream out("submatrix.out");
int a[dim][dim];
int dp[dim][dim];
int n ;
int sol = 0;
void read();
void debug();
void build();
void solve();
int main()
{
    read();
    build();
    solve();
   // debug();
    out << sol;
}
void read()
{
    ifstream in("submatrix.in");
    in >> n;
    for(int i = 1; i <=n; i++)
        for(int j = 1; j<=n; j++)
            in >> a[i][j];
}
void build()
{
    //first line
    for(int i = 1 ; i<=n ; i++)
        dp[1][i] = a[1][i];
    //first column
    for(int i = 1; i<=n; i++)
        dp[i][1] = a[i][1];
}
void solve()
{
    //pornim de la a[2][2]
    for(int i = 2; i<=n; i++)
        for(int j = 2; j<=n; j++)
        {
            if(a[i][j] == 1)
            {
              dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    for(int i = 1 ; i<=n; i++)
        for(int j = 1 ; j<=n; j++)
            if(dp[i][j] > sol)
                sol = dp[i][j];
}
void debug()
{
    for(int i = 1;  i<=n ; i++)
    {
        for(int j = 1; j<=n; j++)
            cerr << dp[i][j] << " ";
        cerr << '\n';
    }
}