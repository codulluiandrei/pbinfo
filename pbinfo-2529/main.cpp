#include <bits/stdc++.h>
#define Nmax 1005
using namespace std;
ifstream fin("subsircomunmaximal.in");
ofstream fout("subsircomunmaximal.out");
char C1[Nmax], C2[Nmax];
int N, M;
int dp[Nmax][Nmax];
char ans[Nmax];
int L = 0;
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
    for(int i = N, j = M; i >= 1 && j >= 1;)
    {
        if(C1[i] == C2[j])
            ans[++L] = C1[i], i--, j--;
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(ans + 1, ans + L + 1);
    fout << (ans + 1) << "\n";
    return 0;
}