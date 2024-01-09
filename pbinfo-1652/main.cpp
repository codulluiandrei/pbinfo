#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

void Citire(int & n , int A[][105])
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if(i == j)
                A[i][j] = 0;
            else
                A[i][j] = INF;
    while(m > 0)
    {
        int i , j , p;
        cin >> i >> j >> p;
        A[i][j] = p;
        m --;
    }
}

void RF(int n , int A[][105])
{
    for(int k = 1 ; k <= n ; k ++)
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                if(A[i][j] > A[i][k] + A[k][j])
                    A[i][j] = A[i][k] + A[k][j];
}

void  AfisMat(int n , int A[][105])
{
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
            cerr << A[i][j] << " ";
        cerr << endl;
    }
    cerr << endl;
}

int main()
{
    int A[105][105], B[105][105], n;
    Citire(n , A);
    for(int i = 1; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            B[i][j] = A[i][j];
    RF(n , B);
    //AfisMat(n, A);
    //AfisMat(n, B);
    int cnt = 0;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if(A[i][j] == B[i][j] && A[i][j] > 0 && A[i][j] < INF)
            {
                cnt ++;
                //cerr << i << " " << j << endl;
            }
    cout << cnt;
    return 0;
}
