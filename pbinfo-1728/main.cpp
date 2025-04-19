#include <iostream>
using namespace std;
int main()
{
    long long n , i , v[100001] , k , ksum = 0 , sum , j , dif ;
    cin>>n>>k;
    for(i = 1; i <= n; i ++)
    {
        cin >> v[i] ;
    }
    for(i = 1;  i < k;  i ++)
    {
        n-- ;
        for(j = 1; j <= n; j ++)
        {
            if(j > 1)
            {
                v[j-1] = sum - dif ;
            }
            if(v[j] < v[j+1])
            {
                dif = v[j+1] - v[j] ;
            }
            else
            {
                dif = v[j] - v[j+1] ;
            }
            sum = v[j] + v[j+1] ;
        }
       v[n] = sum - dif ;
    }
    for(i = 1; i <= n; i ++)
    {
        ksum = ksum + v[i] ;
    }
    cout << ksum ;
    return 0;
}