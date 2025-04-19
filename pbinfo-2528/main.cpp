#include <bits/stdc++.h>
#define Nmax 1005
using namespace std;
ifstream fin("lungimesubsircomunmaximal.in");
ofstream fout("lungimesubsircomunmaximal.out");
char C1[Nmax], C2[Nmax];
int N, M;
int dp[Nmax][Nmax];
int main()
{
    fin >> (C1 + 1) >> (C2 + 1);
    N = strlen(C1 + 1);
    M = strlen(C2 + 1);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(C1[i] == C2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[N][M] << "\n";
    return 0;
}