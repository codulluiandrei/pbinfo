#include <iostream>
using namespace std;
void Citire(int & n , int A[][105])
{
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            A[i][j] = 0;
    while(m > 0)
    {
        int i , j , p;
        cin >> i >> j >> p;
        A[i][j] = A[j][i] = p;
        m --;
    }
}
void Calcul(int n , int A[][105], int linie , int &s ,int &cnt)
{
    s = cnt = 0;
    for(int i = 1 ; i <= n ; i ++)
        if(A[linie][i] != 0)
            s += A[linie][i], cnt ++;
}
int main()
{
    int A[105][105], n;
    Citire(n , A);
    int smin = 10000000, nmin = 1 , nod;
    for(int i = 1 ; i <= n ; i ++)
    {
        int s , cnt;
        Calcul(n , A, i , s , cnt);
        if(s * nmin < smin * cnt)
            nmin = cnt , smin = s, nod = i;
        //cerr << 1.0 * s / cnt << endl;
    }
    cout << nod;
    return 0;
}