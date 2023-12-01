#include <fstream>
#include <iostream>
using namespace std;
ifstream f("spp.in");
ofstream g("spp.out");
int q, x, p;

int binarys(int x, int st, int dr, long long pp)
{
   int sol  = 0;

   long long px = (1LL * x * (x + 1) * (2 * x + 1)) / 6;
   while (st <= dr) {
       int mid = (st + dr) >> 1;
       long long py = (1LL * mid * (mid + 1) * (2 * mid + 1)) / 6;

       if (py - px >= pp)
           sol = mid, dr = mid - 1;
       else
           st = mid + 1;
   }
   return sol;
}
int main()
{
   int i;
   f >> q;
   for (i = 1; i <= q; i++) {
       f >> x >> p;
       int y = binarys(x - 1, x, x + 1500000, 1LL * p * p);
       g << y << '\n';
   }
   return 0;
} 