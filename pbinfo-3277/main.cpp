#include<bits/stdc++.h>
using namespace std;

int a[105][105], n;
int d1[105][105];
int d2[105][105];
int d3[105][105];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

pair<int, int> A[4];

queue< pair<int, int> > q;

void Init()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            d1[i][j] = d2[i][j] = d3[i][j] = 1000000;
}

void Bordare()
{
    int i;
    for (i = 0; i <= n + 1; i++)
        a[0][i] = a[i][0] = a[n + 1][i] = a[i][n + 1] = 1;
}

void Lee(int x, int y, int d[105][105])
{
    int i, j, k;
    d[x][y] = 0;
    q.push({x, y});
    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (k = 0; k < 4; k++)
        {
            x = i + dx[k];
            y = j + dy[k];
            if (a[x][y] == 0 && d[x][y] > d[i][j] + 1)
            {
                d[x][y] = 1 + d[i][j];
                q.push({x, y});
            }
        }
    }
}

void Afisare()
{
    int M = 1000000;
    /// (1,1) - A - B - C - (n,n)
    M = min(M, d1[1][1] + d1[A[2].first][A[2].second] +
            d3[A[2].first][A[2].second] + d3[n][n]);
    /// (1,1) - A - C - B - (n,n)
    M = min(M, d1[1][1] + d1[A[3].first][A[3].second] +
            d2[A[3].first][A[3].second] + d2[n][n]);
    /// (1,1) - B - A - C - (n,n)
    M = min(M, d2[1][1] + d2[A[1].first][A[1].second] +
            d3[A[1].first][A[1].second] + d3[n][n]);
    /// (1,1) - B - C - A - (n,n)
    M = min(M, d2[1][1] + d2[A[3].first][A[3].second] +
            d1[A[3].first][A[3].second] + d1[n][n]);
    /// (1,1) - C - A - B - (n,n)
    M = min(M, d3[1][1] + d3[A[1].first][A[1].second] +
            d2[A[1].first][A[1].second] + d2[n][n]);
    /// (1,1) - C - B - A - (n,n)
    M = min(M, d3[1][1] + d3[A[2].first][A[2].second] +
            d1[A[2].first][A[2].second] + d1[n][n]);
    cout << M;
}

void Citire()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    for (i = 1; i <= 3; i++)
        cin >> A[i].first >> A[i].second;
}

int main()
{
    Citire();
    Bordare();
    Init();
    Lee(A[1].first, A[1].second, d1);
    Lee(A[2].first, A[2].second, d2);
    Lee(A[3].first, A[3].second, d3);
    Afisare();
    return 0 ;
}
