#include <fstream>
using namespace std;
ifstream fin("no_pals.in");
ofstream fout("no_pals.out");
const int mod = 666013;
int n, i, NR, PAL;
int main()
{
   fin >> n;
   fout << "0\n81\n";
   NR = 90;
   PAL = 9;
   for(i = 3; i <= n; ++i)
   {
       if(i % 2 == 1)
       PAL = PAL * 10 % mod;
       NR  = NR * 10 % mod;
       fout << (NR - PAL + mod) % mod << "\n";
   }
    return 0;
}