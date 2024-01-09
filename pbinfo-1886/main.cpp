#include <iostream>
#include <algorithm>

using namespace std;


int n , GMax, greutate[5001], profit[5001];
int C[1001][10001];

int main()
{
    cin >> n >> GMax;
    for(int i = 1 ; i <= n ; i ++)
        cin >> greutate[i] >> profit[i];
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= GMax ; j++)
            if(greutate[i] > j)
                C[i][j] = C[i-1][j];
            else
                C[i][j] = max(C[i-1][j], C[i-1][j-greutate[i]] + profit[i]);
    }
    
    cout << C[n][GMax];
    return 0;
}
