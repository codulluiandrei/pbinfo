#include <iostream>
using namespace std;
int n,m,k,a[1005][1005];
int di[] = {1,1,-1,-1},
    dj[] = {1,-1,1,-1};
int main()
{
    int i,j,p;
    cin >> n >> m >> k;
    for( ; k ; --k)
    {
        cin >> i >> j >> p;
        for(int pp = 0 ; pp < p ; pp ++)
            for(int x = 0 ; x < 4 ; x ++)
            {
                int ii = i + pp * di[x], jj = j + pp * dj[x];
                if(ii > 0 && ii <= n && jj > 0 && jj <= m)
                    a[ii][jj] ++;
            }
    }
    int cnt = 0;
    /*
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j )
            cout << a[i][j] << " ";
        cout << endl;
    }
    */
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j )
            if(a[i][j] == 0)
                cnt ++;
    cout << cnt;
    return 0;
}