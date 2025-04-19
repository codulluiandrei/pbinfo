#include <iostream>
#include <bitset>
using namespace std;
bitset <300035> A;
int main()
{
   int n, x, maxim = 0;
   cin>> n;
   for(int i=1 ; i<=n ; i++)
   {
       cin>> x;
       A[x] = true;
       if(x > maxim)
        maxim = x;
   }
   for(int i=1 ; i<=maxim ; i++)
        if(A[i])
        cout<<i<<" ";
   return 0;
}