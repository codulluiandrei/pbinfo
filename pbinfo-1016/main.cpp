#include <iostream>
using namespace std;
long long n , nr , i ;
int main()
{
    cin >> n ;
    if (n % 2 == 1) nr = 0 ;
         else
            {
                nr = 1 ;
                for (i = 1 ; i <= n / 2 ; i++) nr = nr * i ;
                nr = nr * nr ;
            }
    cout << nr ;
    return 0;
}