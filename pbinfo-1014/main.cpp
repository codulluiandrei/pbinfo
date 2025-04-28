#include <iostream>
using namespace std;
long long n , k , prod , i ;
int main()
{
    cin >> n >> k;
    if(k == 0) prod = 1;
    else {
           prod = 1;
           if(k <= n / 2) k = n - k ;
           for(i = n - k + 1 ; i <= n ; i++) prod = prod * i;
           for(i = 2 ; i <= k ; i++) prod = prod / i;
         }
    cout << prod;
    return 0;
}